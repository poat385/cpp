 
#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>

// Базовый класс DataValidator
class DataValidator {
public:
    virtual void validate(const std::string& data) const = 0; // Чистая виртуальная функция
    virtual ~DataValidator() = default;                       // Виртуальный деструктор
};

// Класс EmailValidator
class EmailValidator : public DataValidator {
public:
    void validate(const std::string& email) const override {
        std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        if (!std::regex_match(email, pattern)) {
            throw std::invalid_argument("Некорректный формат электронной почты.");
        }
    }
};

// Класс PhoneValidator
class PhoneValidator : public DataValidator {
public:
    void validate(const std::string& phoneNumber) const override {
        std::regex pattern(R"(^\+?[1-9]\d{1,14}$)");
        if (!std::regex_match(phoneNumber, pattern)) {
            throw std::invalid_argument("Некорректный формат номера телефона.");
        }
    }
};

// Класс AgeValidator
class AgeValidator : public DataValidator {
public:
    void validate(const std::string& ageStr) const override {
        int age = std::stoi(ageStr);
        if (age < 0 || age > 120) {
            throw std::out_of_range("Возраст должен находиться в диапазоне от 0 до 120 лет.");
        }
    }
};

// Основная программа
int main() {
    try {
        EmailValidator emailValidator;
        emailValidator.validate("valid.email@example.com"); // корректный адрес
        emailValidator.validate("badmail@com");            // некорректный адрес

        PhoneValidator phoneValidator;
        phoneValidator.validate("+79123456789");           // корректный телефон
        phoneValidator.validate("123abc");                 // некорректный телефон

        AgeValidator ageValidator;
        ageValidator.validate("25");                        // корректный возраст
        ageValidator.validate("-1");                        // некорректный возраст
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}