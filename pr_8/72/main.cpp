 
#include <iostream>
#include <string>
#include <stdexcept>

// Базовый класс EmailService
class EmailService {
public:
    virtual void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) = 0;
    virtual ~EmailService() = default; // Виртуальный деструктор
};

// Сервис отправки через SMTP
class SMTPService : public EmailService {
public:
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw std::invalid_argument("Параметры отправки не могут быть пустыми.");
        }
        std::cout << "Отправка через SMTP выполнена успешно." << std::endl;
    }
};

// Сервис отправки через API
class APIService : public EmailService {
public:
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) override {
        if (subject.size() > 100) {
            throw std::length_error("Заголовок письма слишком большой.");
        }
        std::cout << "Отправка через API выполнена успешно." << std::endl;
    }
};

// Моковская служба отправки писем (для тестирования)
class MockEmailService : public EmailService {
public:
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) override {
        std::cout << "Эмуляция отправки письма завершена." << std::endl;
    }
};

// Основная программа
int main() {
    try {
        // Создание экземпляров служб
        SMTPService smtpService;
        APIService apiService;
        MockEmailService mockService;

        // Отправка писем
        smtpService.sendEmail("test@example.com", "Приветствие", "Здравствуйте, это письмо было отправлено через SMTP.");
        apiService.sendEmail("user@test.ru", "Тест API", "Это письмо отправлено через API.");
        mockService.sendEmail("mock@example.org", "Тест мока", "Это письмо отправлено моком.");

        // Проверка на исключение (при пустой строке)
        smtpService.sendEmail("", "", "");
    } catch (const std::exception& e) {
        std::cerr << "Ошибка отправки: " << e.what() << std::endl;
    }

    return 0;
}