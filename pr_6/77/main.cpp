#include <iostream>
#include <string>
#include <stdexcept>

// Абстрактный класс User
class User {
protected:
    std::string username_;
    std::string password_;

public:
    User(const std::string& username, const std::string& password)
        : username_(username), password_(password) {}

    virtual ~User() = default;

    // Виртуальная функция аутентификации
    virtual void authenticate(const std::string& inputUsername, const std::string& inputPassword) const {
        if (inputUsername != username_ || inputPassword != password_) {
            throw std::invalid_argument("Неверные учетные данные");
        }
    }
};

// Подкласс AdminUser
class AdminUser : public User {
public:
    using User::User; // Используем конструктор родителя

    // Специфичная логика аутентификации администратора
    void authenticate(const std::string& inputUsername, const std::string& inputPassword) const override {
        if (inputUsername.empty() || inputPassword.length() < 8) { // Проверка сложности пароля
            throw std::invalid_argument("Пароль администратора должен содержать минимум 8 символов");
        }
        User::authenticate(inputUsername, inputPassword); // Основная проверка от родительского класса
    }
};

// Подкласс RegularUser
class RegularUser : public User {
public:
    using User::User; // Используем конструктор родителя

    // Простая логика аутентификации обычного пользователя
    void authenticate(const std::string& inputUsername, const std::string& inputPassword) const override {
        User::authenticate(inputUsername, inputPassword); // Стандартная проверка учетных данных
    }
};

int main() {
    try {
        // Создание экземпляра обычного пользователя
        RegularUser regularUser("john_doe", "pass123");
        regularUser.authenticate("john_doe", "wrong_password"); // Ошибка: неверный пароль
    } catch (const std::exception& e) {
        std::cerr << "Ошибка аутентификации регулярного пользователя: " << e.what() << '\n';
    }

    try {
        // Создание экземпляра админа
        AdminUser adminUser("admin", "strong_pass123");
        adminUser.authenticate("", ""); // Ошибка: пустые имя и пароль
    } catch (const std::exception& e) {
        std::cerr << "Ошибка аутентификации администратора: " << e.what() << '\n';
    }

    return 0;
}