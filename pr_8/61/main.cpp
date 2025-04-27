#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

// Базовый класс DataProcessor
class DataProcessor {
public:
    virtual ~DataProcessor() {}
    
    virtual void process(const std::string& data) {
        if (data.empty()) {
            throw std::invalid_argument("Empty data provided");
        }
    }
    
    virtual std::string getType() const {
        return "Generic";
    }
};

// Класс для обработки CSV данных
class CSVProcessor : public DataProcessor {
public:
    void process(const std::string& data) override {
        DataProcessor::process(data); // Проверка на пустые данные
        
        // Проверка на минимальные требования CSV (хотя бы одна запятая)
        if (data.find(',') == std::string::npos) {
            throw std::runtime_error("Invalid CSV format - no commas found");
        }
        
        // Дополнительная проверка на количество полей
        size_t firstLineEnd = data.find('\n');
        std::string firstLine = (firstLineEnd == std::string::npos) ? data : data.substr(0, firstLineEnd);
        size_t commaCount = std::count(firstLine.begin(), firstLine.end(), ',');
        
        if (commaCount < 1) {
            throw std::runtime_error("CSV must contain at least 2 columns");
        }
        
        std::cout << "Processing CSV data with " << (commaCount + 1) << " columns" << std::endl;
    }
    
    std::string getType() const override {
        return "CSV";
    }
};

// Класс для обработки JSON данных
class JSONProcessor : public DataProcessor {
public:
    void process(const std::string& data) override {
        DataProcessor::process(data); // Проверка на пустые данные
        
        // Простейшая проверка формата JSON
        size_t openBrace = data.find('{');
        size_t closeBrace = data.find('}');
        
        if (openBrace == std::string::npos || closeBrace == std::string::npos || closeBrace <= openBrace) {
            throw std::runtime_error("Invalid JSON format - braces mismatch");
        }
        
        // Проверка на наличие хотя бы одного ключа
        size_t colonPos = data.find(':');
        if (colonPos == std::string::npos || colonPos < openBrace || colonPos > closeBrace) {
            throw std::runtime_error("Invalid JSON format - no key-value pairs");
        }
        
        std::cout << "Processing valid JSON data" << std::endl;
    }
    
    std::string getType() const override {
        return "JSON";
    }
};

// Класс для обработки XML данных
class XMLProcessor : public DataProcessor {
public:
    void process(const std::string& data) override {
        DataProcessor::process(data); // Проверка на пустые данные
        
        // Проверка на наличие открывающего и закрывающего тегов
        size_t openTag = data.find('<');
        size_t closeTag = data.find('>');
        
        if (openTag == std::string::npos || closeTag == std::string::npos || closeTag <= openTag) {
            throw std::runtime_error("Invalid XML format - tag mismatch");
        }
        
        // Проверка на закрывающий тег
        size_t closingTag = data.find("</", openTag + 1);
        if (closingTag == std::string::npos) {
            throw std::runtime_error("Invalid XML format - no closing tag");
        }
        
        // Извлечение имени тега
        std::string tagName = data.substr(openTag + 1, closeTag - openTag - 1);
        if (tagName.empty()) {
            throw std::runtime_error("Invalid XML format - empty tag name");
        }
        
        std::cout << "Processing XML data with root tag <" << tagName << ">" << std::endl;
    }
    
    std::string getType() const override {
        return "XML";
    }
};

// Функция для тестирования обработчиков
void testProcessor(DataProcessor* processor, const std::string& testData) {
    std::cout << "\nTesting " << processor->getType() << " processor..." << std::endl;
    std::cout << "Test data: " << (testData.empty() ? "[empty]" : testData.substr(0, 20) + "...") << std::endl;
    
    try {
        processor->process(testData);
        std::cout << "Data processed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Processing error: " << e.what() << std::endl;
    }
}

int main() {
    // Создаем обработчики
    CSVProcessor csvProcessor;
    JSONProcessor jsonProcessor;
    XMLProcessor xmlProcessor;
    
    // Тестовые данные
    std::string validCSV = "id,name,age\n1,John,30\n2,Alice,25";
    std::string invalidCSV = "id name age"; // Нет запятых
    
    std::string validJSON = "{\"name\":\"John\", \"age\":30}";
    std::string invalidJSON = "{name:John, age:30}"; // Нет кавычек
    
    std::string validXML = "<person><name>John</name><age>30</age></person>";
    std::string invalidXML = "<person><name>John<age>30</age>"; // Незакрытый тег name
    
    // Тестируем обработчики
    testProcessor(&csvProcessor, validCSV);
    testProcessor(&csvProcessor, invalidCSV);
    testProcessor(&csvProcessor, ""); // Пустые данные
    
    testProcessor(&jsonProcessor, validJSON);
    testProcessor(&jsonProcessor, invalidJSON);
    
    testProcessor(&xmlProcessor, validXML);
    testProcessor(&xmlProcessor, invalidXML);
    
    // Тестирование через вектор указателей на базовый класс
    std::vector<DataProcessor*> processors = {&csvProcessor, &jsonProcessor, &xmlProcessor};
    std::string testData = "<test>data</test>";
    
    std::cout << "\nTesting all processors with XML data:\n";
    for (auto processor : processors) {
        testProcessor(processor, testData);
    }
    
    return 0;
}