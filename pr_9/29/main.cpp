#include <iostream>
#include <stdexcept>
#include <string>

class UserProfile {
protected:
    std::string username;
    std::string password;

public:
    UserProfile(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd) {}

    virtual ~UserProfile() = default;

    virtual void updateProfile(const std::string& newUsername, const std::string& newPassword) {
        if (newUsername.empty() || newPassword.length() < 6) {
            throw std::invalid_argument("Имя пользователя должно быть ненулевым, пароль должен быть не менее 6 символов.");
        }
        username = newUsername;
        password = newPassword;
    }

    void displayProfile() const {
        std::cout << "Пользователь: " << username << ", Пароль: " << password << std::endl;
    }
};

class AdminProfile : public UserProfile {
public:
    using UserProfile::UserProfile; 

    void updateProfile(const std::string& newUsername, const std::string& newPassword) override {
        if (newUsername.empty() || newPassword.length() < 8) {
            throw std::invalid_argument("Пароль администратора должен быть не менее 8 символов.");
        }
        UserProfile::updateProfile(newUsername, newPassword);
    }
};

class GuestProfile : public UserProfile {
public:
    using UserProfile::UserProfile; 

    void updateProfile(const std::string& newUsername, const std::string&) override {
        if (newUsername.empty()) {
            throw std::invalid_argument("Имя пользователя гостя не может быть пустым.");
        }
        username = newUsername;
    }
};

// Основная функция
int main() {
    try {
        // Обычный пользователь
        UserProfile regular_user("john_doe", "password123");
        regular_user.updateProfile("jane_doe", "passwrd"); 
        regular_user.displayProfile();

        // Администратор
        AdminProfile admin_profile("admin", "securepwd");
        admin_profile.updateProfile("super_admin", "weak_pass"); 
        admin_profile.displayProfile();

        // Гостевой аккаунт
        GuestProfile guest_profile("", "");
        guest_profile.updateProfile("guest_user", ""); 
        guest_profile.displayProfile();
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}