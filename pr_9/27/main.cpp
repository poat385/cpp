#include <iostream>
#include <stdexcept>

class Notification {
public:
    virtual ~Notification() = default;
    virtual void send() const = 0;
};

class EmailNotification : public Notification {
private:
    std::string recipient_email_;
    std::string content_;

public:
    EmailNotification(const std::string& recipient_email, const std::string& content)
        : recipient_email_(recipient_email), content_(content) {}

    void send() const override {
        bool success = simulateSending();
        if (!success) {
            throw std::runtime_error("Ошибка отправки E-mail уведомления.");
        }
        std::cout << "E-mail отправлен на адрес: " << recipient_email_ << ". Контент: " << content_ << std::endl;
    }

private:
    bool simulateSending() const {
        return true;
    }
};

class SMSNotification : public Notification {
private:
    std::string phone_number_;
    std::string content_;

public:
    SMSNotification(const std::string& phone_number, const std::string& content)
        : phone_number_(phone_number), content_(content) {}

    void send() const override {
        bool success = simulateSending(); 
        if (!success) {
            throw std::runtime_error("Ошибка отправки SMS уведомления.");
        }
        std::cout << "SMS отправлено на номер: " << phone_number_ << ". Контент: " << content_ << std::endl;
    }

private:
    bool simulateSending() const {
        return true;
    }
};

int main() {
    try {
        EmailNotification email_notification("user@example.com", "Привет! Это тестовое письмо.");
        email_notification.send();

        SMSNotification sms_notification("+79001234567", "Ваш заказ принят.");
        sms_notification.send();
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}