#include <iostream>
#include <stdexcept>
#include <string>

// Базовый класс Session
class Session {
protected:
    bool isActive;
    std::string sessionType;

public:
    Session(const std::string& type) : isActive(false), sessionType(type) {}

    virtual void start() {
        if (isActive) {
            throw std::runtime_error(sessionType + " session is already active");
        }
        isActive = true;
        std::cout << sessionType << " session started" << std::endl;
    }

    virtual void end() {
        if (!isActive) {
            throw std::runtime_error("No active " + sessionType + " session to end");
        }
        isActive = false;
        std::cout << sessionType << " session ended" << std::endl;
    }

    bool getStatus() const {
        return isActive;
    }

    virtual ~Session() {}
};

// Класс UserSession
class UserSession : public Session {
private:
    int maxSessions;
    static int activeUserSessions;

public:
    UserSession() : Session("User"), maxSessions(3) {}

    void start() override {
        if (activeUserSessions >= maxSessions) {
            throw std::runtime_error("Maximum number of user sessions reached");
        }

        Session::start(); // Вызываем базовую реализацию
        activeUserSessions++;
    }

    void end() override {
        if (getStatus()) {
            activeUserSessions--;
        }
        Session::end(); // Вызываем базовую реализацию
    }

    static int getActiveUserSessions() {
        return activeUserSessions;
    }
};

int UserSession::activeUserSessions = 0;

// Класс AdminSession
class AdminSession : public Session {
private:
    bool maintenanceMode;

public:
    AdminSession() : Session("Admin"), maintenanceMode(false) {}

    void start() override {
        if (maintenanceMode) {
            throw std::runtime_error("Cannot start admin session during maintenance");
        }

        Session::start(); // Вызываем базовую реализацию
    }

    void setMaintenanceMode(bool mode) {
        if (getStatus() && mode) {
            throw std::runtime_error("Cannot enable maintenance mode while admin session is active");
        }
        maintenanceMode = mode;
        std::cout << "Maintenance mode " << (mode ? "enabled" : "disabled") << std::endl;
    }

    bool getMaintenanceMode() const {
        return maintenanceMode;
    }
};

// Функция для тестирования сессий
void testSession(Session* session) {
    try {
        std::cout << "\nTesting " << (dynamic_cast<UserSession*>(session) ? "User" : "Admin") << " session..." << std::endl;
        
        // Попытка начать сессию
        session->start();
        
        // Попытка начать уже активную сессию
        try {
            session->start();
        } catch (const std::exception& e) {
            std::cout << "Expected error: " << e.what() << std::endl;
        }
        
        // Завершение сессии
        session->end();
        
        // Попытка завершить уже неактивную сессию
        try {
            session->end();
        } catch (const std::exception& e) {
            std::cout << "Expected error: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    // Тестирование UserSession
    UserSession user1, user2, user3, user4;
    
    testSession(&user1);
    testSession(&user2);
    testSession(&user3);
    
    try {
        // Попытка создать четвертую пользовательскую сессию
        std::cout << "\nTrying to start 4th user session..." << std::endl;
        user4.start();
    } catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
    
    // Тестирование AdminSession
    AdminSession admin;
    testSession(&admin);
    
    try {
        // Попытка включить режим обслуживания при активной сессии
        std::cout << "\nTrying to enable maintenance during active session..." << std::endl;
        admin.start();
        admin.setMaintenanceMode(true);
    } catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
        admin.end();
    }
    
    // Включение режима обслуживания
    admin.setMaintenanceMode(true);
    
    try {
        // Попытка начать сессию в режиме обслуживания
        std::cout << "\nTrying to start admin session during maintenance..." << std::endl;
        admin.start();
    } catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
    
    return 0;
}