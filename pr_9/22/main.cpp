#include <iostream>
#include <stdexcept>

class Database {
public:
    virtual ~Database() = default;

    virtual void connect() = 0; 
};

class MySQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "Подключаемся к MySQL..." << std::endl;
        
        std::cout << "Подключение к MySQL выполнено успешно." << std::endl;
    }
};

class SQLiteDatabase : public Database {
public:
    void connect() override {
        std::cout << "Подключаемся к SQLite..." << std::endl;
        
        bool connectionSuccess = false;
                
        if (!connectionSuccess) {
            throw std::runtime_error("Ошибка подключения к SQLite.");
        }
        
        std::cout << "Подключение к SQLite выполнено успешно." << std::endl;
    }
};

// Точка входа
int main() {
    try {
        MySQLDatabase mysqlDb;
        mysqlDb.connect(); 

        SQLiteDatabase sqliteDb;
        sqliteDb.connect(); 
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}