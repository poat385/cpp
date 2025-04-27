#include <iostream>
#include <string>
#include <stdexcept>

// Базовый класс UserProfile
class UserProfile {
public:
    virtual void save(const std::string& profileData) = 0; // чистая виртуальная функция
    virtual ~UserProfile() = default;                      // виртуальный деструктор
};

// Профиль административного пользователя
class AdminProfile : public UserProfile {
public:
    void save(const std::string& profileData) override {
        if (profileData.size() > 100) {
            throw std::length_error("Размер данных превышает допустимый предел для административного профиля.");
        }
        std::cout << "Административный профиль успешно сохранён." << std::endl;
    }
};

// Обычный пользовательский профиль
class RegularProfile : public UserProfile {
public:
    void save(const std::string& profileData) override {
        if (profileData.empty()) {
            throw std::invalid_argument("Обычные профили не могут быть пустыми.");
        }
        std::cout << "Пользовательский профиль успешно сохранён." << std::endl;
    }
};

// Основная программа для тестирования
int main() {
    try {
        AdminProfile adminProfile;
        adminProfile.save("This is a valid short admin profile.");
        
        RegularProfile regularProfile;
        regularProfile.save("");
    } catch (const std::exception& e) {
        std::cerr << "Ошибка при сохранении профиля: " << e.what() << std::endl;
    }

    return 0;
}