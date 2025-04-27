#include <iostream>
#include <string>
#include <stdexcept>

// Базовый класс Notification
class Notification {
public:
    virtual void send(const std::string& message) const {
        // Базовая реализация, которая просто выводит сообщение
        std::cout << "Base notification: " << message << std::endl;
    }
    
    virtual ~Notification() {} // Виртуальный деструктор
};

// Класс для email-уведомлений
class EmailNotification : public Notification {
public:
    EmailNotification(const std::string& email) : email_(email) {}
    
    void send(const std::string& message) const override {
        // Имитация возможной ошибки при отправке
        if (message.empty()) {
            throw std::runtime_error("Email notification error: message is empty");
        }
        
        if (email_.empty() || email_.find('@') == std::string::npos) {
            throw std::runtime_error("Email notification error: invalid email address");
        }
        
        std::cout << "Sending email to " << email_ << ": " << message << std::endl;
        // Здесь была бы реальная логика отправки email
    }

private:
    std::string email_;
};

// Класс для SMS-уведомлений
class SMSNotification : public Notification {
public:
    SMSNotification(const std::string& phone) : phone_(phone) {}
    
    void send(const std::string& message) const override {
        // Имитация возможной ошибки при отправке
        if (message.empty()) {
            throw std::runtime_error("SMS notification error: message is empty");
        }
        
        if (phone_.empty() || phone_.length() < 10) {
            throw std::runtime_error("SMS notification error: invalid phone number");
        }
        
        std::cout << "Sending SMS to " << phone_ << ": " << message << std::endl;
        // Здесь была бы реальная логика отправки SMS
    }

private:
    std::string phone_;
};

// Класс для push-уведомлений
class PushNotification : public Notification {
public:
    PushNotification(const std::string& deviceId) : deviceId_(deviceId) {}
    
    void send(const std::string& message) const override {
        // Имитация возможной ошибки при отправке
        if (message.empty()) {
            throw std::runtime_error("Push notification error: message is empty");
        }
        
        if (deviceId_.empty()) {
            throw std::runtime_error("Push notification error: invalid device ID");
        }
        
        std::cout << "Sending push to device " << deviceId_ << ": " << message << std::endl;
        // Здесь была бы реальная логика отправки push-уведомления
    }

private:
    std::string deviceId_;
};

// Функция для тестирования отправки уведомлений
void testNotification(Notification* notifier, const std::string& message) {
    try {
        notifier->send(message);
        std::cout << "Notification sent successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    // Тестирование различных уведомлений
    EmailNotification emailNotify("user@example.com");
    SMSNotification smsNotify("+1234567890");
    PushNotification pushNotify("device-12345");
    
    std::cout << "=== Testing valid notifications ===" << std::endl;
    testNotification(&emailNotify, "Hello via Email!");
    testNotification(&smsNotify, "Hello via SMS!");
    testNotification(&pushNotify, "Hello via Push!");
    
    std::cout << "\n=== Testing invalid notifications ===" << std::endl;
    EmailNotification badEmailNotify("");
    SMSNotification badSmsNotify("123");
    PushNotification badPushNotify("");
    
    testNotification(&badEmailNotify, "This should fail");
    testNotification(&badSmsNotify, "This should fail");
    testNotification(&badPushNotify, "This should fail");
    testNotification(&emailNotify, ""); // Пустое сообщение
    
    return 0;
}