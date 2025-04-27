 
#include <iostream>
#include <string>
#include <stdexcept>

// Базовый класс сервиса уведомлений
class NotificationService {
public:
    virtual ~NotificationService() = default;

    // Виртуальная функция отправки уведомления
    virtual void sendNotification(const std::string& message) const {
        throw std::runtime_error("Ошибка отправки уведомления: базовая реализация не поддерживает отправку.");
    }
};

// Сервис отправки уведомлений по электронной почте
class EmailNotificationService : public NotificationService {
    public:
        void sendNotification(const std::string& message) const override {
            // Логика отправки email-сообщения
            if (message.empty()) {
                throw std::runtime_error("Ошибка отправки email: сообщение пустое.");
            }
            std::cout << "Отправлено email-уведомление: " << message << std::endl;
        }
};

// Сервис отправки уведомлений через SMS
class SMSNotificationService : public NotificationService {
    public:
        void sendNotification(const std::string& message) const override {
            // Логика отправки SMS-сообщения
            if (message.length() > 160) {
                throw std::runtime_error("Ошибка отправки SMS: сообщение слишком длинное.");
            }
            std::cout << "Отправлено SMS-уведомление: " << message << std::endl;
        }
};

// Сервис отправки push-уведомлений
class PushNotificationService : public NotificationService {
    public:
        void sendNotification(const std::string& message) const override {
            // Логика отправки push-уведомления
            if (message.empty()) {
                throw std::runtime_error("Ошибка отправки push-уведомления: сообщение пустое.");
            }
            std::cout << "Отправлено push-уведомление: " << message << std::endl;
        }
};

int main() {
    try {
        // Отправляем уведомления различными способами
        EmailNotificationService emailService;
        emailService.sendNotification("Привет! Это тестовое email-уведомление.");

        SMSNotificationService smsService;
        smsService.sendNotification("Это короткое SMS-уведомление.");

        PushNotificationService pushService;
        pushService.sendNotification("Это push-уведомление.");

        // Тестируем случаи возникновения ошибок
        EmailNotificationService emptyMessageService;
        emptyMessageService.sendNotification("");

        SMSNotificationService longSmsService;
        longSmsService.sendNotification(std::string(161, 'X')); // Сообщение слишком длинное
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}