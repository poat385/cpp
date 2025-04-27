#include <iostream>
#include <stdexcept>

class Transaction {
public:
    virtual ~Transaction() = default;
    virtual void commit(bool s) = 0;
};

class BankTransaction : public Transaction {
public:
    void commit(bool s) override {
        bool success = s; 
        if (!success) {
            throw std::runtime_error("Ошибка выполнения банковской транзакции");
        }
        std::cout << "Банковская транзакция выполнена успешно" << std::endl;
    }
};

class CryptoTransaction : public Transaction {
public:
    void commit(bool s) override {
        bool success = s; 
        if (!success) {
            throw std::runtime_error("Ошибка выполнения криптографической транзакции");
        }
        std::cout << "Криптографическая транзакция выполнена успешно" << std::endl;
    }
};

int main() {
    try {
        BankTransaction bankTrans;
        bankTrans.commit(true);

        CryptoTransaction cryptoTrans;
        cryptoTrans.commit(true);

        BankTransaction bankTrans1;
        bankTrans1.commit(false);

        CryptoTransaction cryptoTrans1;
        cryptoTrans1.commit(false);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}