#include <iostream>
#include <fstream>
#include <stdexcept>

class FileReader {
public:
    virtual ~FileReader() = default;
    virtual void read(const std::string& filename) = 0;
};

class TextFileReader : public FileReader {
public:
    void read(const std::string& filename) override {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Ошибка открытия текстового файла.");
        }
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
};

class BinaryFileReader : public FileReader {
public:
    void read(const std::string& filename) override {
        std::ifstream file(filename, std::ios::binary | std::ios::in);
        if (!file.is_open()) {
            throw std::runtime_error("Ошибка открытия бинарного файла.");
        }
        char buffer[1024];
        while (file.read(buffer, sizeof(buffer))) {
            std::cout.write(buffer, file.gcount());
        }
        file.close();
    }
};

// Тестовая функция
int main() {
    try {
        TextFileReader txt_reader;
        txt_reader.read("test.txt");

        BinaryFileReader bin_reader;
        bin_reader.read("binary.bin");
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}