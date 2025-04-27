 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

// Абстрактный класс DataProcessor
class DataProcessor {
public:
    virtual ~DataProcessor() = default;

    // Виртуальная функция обработки данных
    virtual void processData(const std::string& data) const {
        throw std::runtime_error("Ошибка! Некорректные входные данные.");
    }
};

// Класс для обработки CSV-файлов
class CSVDataProcessor : public DataProcessor {
public:
    void processData(const std::string& csvData) const override {
        std::istringstream stream(csvData);
        std::string line;
        while (std::getline(stream, line)) {
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> row;
            while (std::getline(ss, token, ',')) {
                row.push_back(token);
            }
            if (row.size() == 0) {
                throw std::runtime_error("Ошибка! Пустая строка в CSV-данных.");
            }
            // Обработка строки CSV
            for (const auto& col : row) {
                std::cout << col << ' ';
            }
            std::cout << '\n';
        }
    }
};

// Класс для обработки XML-документов
class XMLDataProcessor : public DataProcessor {
public:
    void processData(const std::string& xmlData) const override {
        if (xmlData.find("<root>") == std::string::npos ||
            xmlData.find("</root>") == std::string::npos) {
            throw std::runtime_error("Ошибка! Некорректный XML-документ.");
        }
        // Простая обработка XML
        std::cout << "Обработан XML-документ:\n" << xmlData << '\n';
    }
};

// Класс для обработки JSON-данных
class JSONDataProcessor : public DataProcessor {
public:
    void processData(const std::string& jsonData) const override {
        if (jsonData.front() != '{' || jsonData.back() != '}') {
            throw std::runtime_error("Ошибка! Некорректный JSON.");
        }
        // Простая обработка JSON
        std::cout << "Обработаны JSON-данные:\n" << jsonData << '\n';
    }
};

int main() {
    try {
        CSVDataProcessor csvProc;
        csvProc.processData("Name,Age\nJohn,30\nAlice,25");

        XMLDataProcessor xmlProc;
        xmlProc.processData("<root><person>John Doe</person></root>");

        JSONDataProcessor jsonProc;
        jsonProc.processData(R"({"name": "Jane", "age": 28})");
    } catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << '\n';
    }

    return 0;
}