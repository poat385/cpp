#include <iostream>
#include <stdexcept>

class EmailService {
public:
    virtual ~EmailService() = default;
    virtual void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) = 0;
};

class SMTPService : public EmailService {
public:
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw std::runtime_error("SMTPService: Недопустимые параметры отправки.");
        }
        std::cout << "Отправлен email через SMTPService на адрес: " << recipient << std::endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw std::runtime_error("APIService: Недопустимые параметры отправки.");
        }
        std::cout << "Отправлен email через APIService на адрес: " << recipient << std::endl;
    }
};

int main() {
    try {
        SMTPService smtpService;
        smtpService.sendEmail("user@example.com", "Test Subject", "This is the test email body.");

        APIService apiService;
        apiService.sendEmail("user@example.com", "", "Body of API service email.");
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}