#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

// Базовый класс FileReader
class FileReader {
public:
    virtual std::string read(const std::string &filePath) = 0; // Чистая виртуальная функция
    virtual ~FileReader() = default;                           // Виртуальный деструктор
};

// Читатель текстовых файлов
class TextFileReader : public FileReader {
public:
    std::string read(const std::string &filePath) override {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Файл не найден или невозможно открыть файл.");
        }

        std::stringstream buffer;
        buffer << file.rdbuf(); // Копирование содержимого файла в буфер
        return buffer.str();
    }
};

// Читатель бинарных файлов
class BinaryFileReader : public FileReader {
public:
    std::string read(const std::string &filePath) override {
        std::ifstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Файл не найден или невозможно открыть файл.");
        }

        std::ostringstream buffer;
        buffer << file.rdbuf(); // Бинарные данные записываем в строку
        return buffer.str();
    }
};

// Читатель JSON-файлов (простая версия без полноценной библиотеки)
class JsonFileReader : public FileReader {
public:
    std::string read(const std::string &filePath) override {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Файл не найден или невозможно открыть файл.");
        }

        std::stringstream buffer;
        buffer << file.rdbuf(); // Загружаем весь файл в строку
        std::string content = buffer.str();

        // Простая проверка структуры JSON (неполноценная, только минимальная логика)
        if ((content.front() != '{') || (content.back() != '}')) {
            throw std::runtime_error("Неверный формат JSON-файла.");
        }

        return content;
    }
};

// Основная демонстрационная программа
int main() {
    try {
        TextFileReader textReader;
        auto textContent = textReader.read("example.txt");
        std::cout << "Текстовый файл:\n" << textContent << std::endl;

        BinaryFileReader binaryReader;
        auto binaryData = binaryReader.read("example.bin");
        std::cout << "Бинарный файл (строкой):\n" << binaryData << std::endl;

        JsonFileReader jsonReader;
        auto jsonContent = jsonReader.read("test.json");
        std::cout << "JSON-файл:\n" << jsonContent << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}