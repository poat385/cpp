#include <iostream>
#include <stdexcept>

class PaymentProcessor {
public:
    virtual ~PaymentProcessor() = default;
    virtual void processPayment(double amount) = 0;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        if (amount > balance) {
            throw std::runtime_error("Недостаточный баланс кредитной карты");
        }
        std::cout << "Оплата кредитной картой на сумму $" << amount << " произведена успешно.\n";
    }
private:
    double balance = 1000.0;
};

class DebitCardProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        if (amount > balance) {
            throw std::runtime_error("Недостаточный баланс дебетовой карты");
        }
        std::cout << "Оплата дебетовой картой на сумму $" << amount << " произведена успешно.\n";
    }
private:
    double balance = 500.0;
};

int main() {
    try {
        CreditCardProcessor creditCardProc;
        creditCardProc.processPayment(800.0);

        DebitCardProcessor debitCardProc;
        debitCardProc.processPayment(600.0); // Недостаточно баланса
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}