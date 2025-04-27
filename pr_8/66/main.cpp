 
#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>

// Базовый класс PaymentGateway
class PaymentGateway {
protected:
    std::string transactionId;
    double amount;
    std::string currency;

    // Генерация уникального ID транзакции
    std::string generateTransactionId() {
        time_t now = time(0);
        return "TXN" + std::to_string(now);
    }

public:
    PaymentGateway(double amt, const std::string& curr = "USD") 
        : amount(amt), currency(curr) {
        transactionId = generateTransactionId();
        
        if (amount <= 0) {
            throw std::invalid_argument("Amount must be positive");
        }
        if (currency.length() != 3) {
            throw std::invalid_argument("Currency code must be 3 characters");
        }
    }

    // Виртуальная функция обработки платежа
    virtual void processPayment() {
        throw std::runtime_error("Payment processing not implemented");
    }

    virtual ~PaymentGateway() = default;
};

// Класс StripeGateway
class StripeGateway : public PaymentGateway {
private:
    std::string cardToken;
    std::string description;

public:
    StripeGateway(double amt, const std::string& token, 
                 const std::string& desc = "", const std::string& curr = "USD")
        : PaymentGateway(amt, curr), cardToken(token), description(desc) {
        
        if (cardToken.length() < 10) {
            throw std::invalid_argument("Invalid card token");
        }
    }

    void processPayment() override {
        std::cout << "Processing Stripe payment (" << transactionId << ")\n";
        std::cout << "Amount: " << amount << " " << currency << "\n";
        std::cout << "Description: " << (description.empty() ? "none" : description) << "\n";

        // Имитация возможной ошибки Stripe
        if (amount > 10000) {
            throw std::runtime_error("Stripe: Amount exceeds maximum limit");
        }
        if (currency != "USD" && currency != "EUR") {
            throw std::runtime_error("Stripe: Unsupported currency");
        }

        // Здесь была бы реальная интеграция со Stripe API
        std::cout << "Stripe payment processed successfully\n";
    }
};

// Класс PayPalGateway
class PayPalGateway : public PaymentGateway {
private:
    std::string payerEmail;
    std::string receiverEmail;

public:
    PayPalGateway(double amt, const std::string& payer, 
                 const std::string& receiver = "merchant@example.com", 
                 const std::string& curr = "USD")
        : PaymentGateway(amt, curr), payerEmail(payer), receiverEmail(receiver) {
        
        if (payerEmail.find('@') == std::string::npos) {
            throw std::invalid_argument("Invalid payer email");
        }
        if (receiverEmail.find('@') == std::string::npos) {
            throw std::invalid_argument("Invalid receiver email");
        }
    }

    void processPayment() override {
        std::cout << "Processing PayPal payment (" << transactionId << ")\n";
        std::cout << "Amount: " << amount << " " << currency << "\n";
        std::cout << "From: " << payerEmail << " to " << receiverEmail << "\n";

        // Имитация возможной ошибки PayPal
        if (amount < 1.0) {
            throw std::runtime_error("PayPal: Minimum amount is 1.0");
        }
        if (payerEmail == receiverEmail) {
            throw std::runtime_error("PayPal: Sender and receiver cannot be same");
        }

        // Здесь была бы реальная интеграция с PayPal API
        std::cout << "PayPal payment processed successfully\n";
    }
};

// Класс SquareGateway
class SquareGateway : public PaymentGateway {
private:
    std::string locationId;
    std::string customerId;

public:
    SquareGateway(double amt, const std::string& locId, 
                 const std::string& custId = "guest", 
                 const std::string& curr = "USD")
        : PaymentGateway(amt, curr), locationId(locId), customerId(custId) {
        
        if (locationId.empty()) {
            throw std::invalid_argument("Location ID cannot be empty");
        }
    }

    void processPayment() override {
        std::cout << "Processing Square payment (" << transactionId << ")\n";
        std::cout << "Amount: " << amount << " " << currency << "\n";
        std::cout << "Location: " << locationId << ", Customer: " << customerId << "\n";

        // Имитация возможной ошибки Square
        if (currency == "RUB") {
            throw std::runtime_error("Square: Payments in RUB are not supported");
        }
        if (customerId.length() > 50) {
            throw std::runtime_error("Square: Customer ID too long");
        }

        // Здесь была бы реальная интеграция с Square API
        std::cout << "Square payment processed successfully\n";
    }
};

int main() {
    try {
        // Демонстрация работы Stripe
        StripeGateway stripe(99.99, "tok_visa1234", "Monthly subscription");
        stripe.processPayment();

        // Демонстрация работы PayPal
        PayPalGateway paypal(50.0, "customer@example.com");
        paypal.processPayment();

        // Демонстрация работы Square
        SquareGateway square(25.75, "LOC12345", "CUST67890");
        square.processPayment();

        // Демонстрация обработки ошибок
        StripeGateway badStripe(15000.0, "invalid"); // Выбросит исключение
        PayPalGateway badPaypal(0.5, "invalid-email"); // Выбросит исключение
    }
    catch (const std::exception& e) {
        std::cerr << "Payment error: " << e.what() << std::endl;
    }

    return 0;
}