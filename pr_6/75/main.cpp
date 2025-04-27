 
#include <iostream>
#include <stdexcept>

// Базовый класс Transaction
class Transaction {
public:
    virtual void execute(double balance) = 0; // Чистая виртуальная функция
    virtual ~Transaction() = default;         // Виртуальный деструктор
};

// Класс DepositTransaction (операция внесения средств)
class DepositTransaction : public Transaction {
private:
    double amount; // сумма депозита

public:
    DepositTransaction(double amt) : amount(amt) {
        if (amount <= 0) {
            throw std::invalid_argument("Сумма депозита должна быть положительной.");
        }
    }

    void execute(double currentBalance) override {
        std::cout << "Пополнение счета на сумму " << amount << std::endl;
        std::cout << "Новый баланс: " << currentBalance + amount << std::endl;
    }
};

// Класс WithdrawalTransaction (операция снятия средств)
class WithdrawalTransaction : public Transaction {
private:
    double amount; // сумма снятия

public:
    WithdrawalTransaction(double amt) : amount(amt) {
        if (amount <= 0) {
            throw std::invalid_argument("Сумма снятия должна быть положительной.");
        }
    }

    void execute(double currentBalance) override {
        if (currentBalance < amount) {
            throw std::runtime_error("Недостаточный баланс для совершения операции.");
        }

        std::cout << "Снятие суммы " << amount << std::endl;
        std::cout << "Новый баланс: " << currentBalance - amount << std::endl;
    }
};

// Главная программа для тестирования
int main() {
    try {
        // Положительная транзакция депозита
        DepositTransaction deposit(100.0);
        deposit.execute(500.0); // Текущий баланс равен 500

        // Негативная транзакция снятия (недостаточно средств)
        WithdrawalTransaction withdrawal(600.0);
        withdrawal.execute(500.0); // Текущий баланс равен 500

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}