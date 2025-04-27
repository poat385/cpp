#include <iostream>
#include <string>
#include <stdexcept>

// Базовый класс обработчика исключений
class ExceptionHandler {
public:
    virtual void handle(const std::string& data) = 0; // Чистая виртуальная функция
    virtual ~ExceptionHandler() = default;           // Виртуальный деструктор
};

// Обработчик исключений, связанный с проблемами файлов
class FileExceptionHandler : public ExceptionHandler {
public:
    void handle(const std::string& filename) override {
        if (filename.empty()) {
            throw std::invalid_argument("Название файла не может быть пустым!");
        }
        std::cout << "Файл '" << filename << "' успешно обработан." << std::endl;
    }
};

// Обработчик исключений, связанный с сетевыми проблемами
class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const std::string& address) override {
        if (address.empty()) {
            throw std::invalid_argument("Адрес сети не может быть пустым!");
        }
        std::cout << "Сеть по адресу '" << address << "' успешно подключена." << std::endl;
    }
};

// Обработчик исключений, связанный с ошибками ввода-вывода
class InputExceptionHandler : public ExceptionHandler {
public:
    void handle(const std::string& input_data) override {
        if (input_data.empty()) {
            throw std::invalid_argument("Данные ввода не могут быть пустыми!");
        }
        std::cout << "Введены данные: '" << input_data << "'" << std::endl;
    }
};

// Основной блок тестирования
int main() {
    try {
        FileExceptionHandler file_handler;
        file_handler.handle("example.txt"); // Правильно указанный файл

        NetworkExceptionHandler network_handler;
        network_handler.handle("localhost"); // Правильный сетевой адрес

        InputExceptionHandler input_handler;
        input_handler.handle("Hello World"); // Корректные данные ввода

        // Генерация исключений
        file_handler.handle(""); // Некорректный пустой файл
        network_handler.handle(""); // Некорректный пустой адрес
        input_handler.handle(""); // Пустой ввод
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}