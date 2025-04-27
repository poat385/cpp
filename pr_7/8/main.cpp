#include <iostream>
#include <stdexcept> 
#include <algorithm> 

template <typename T>
class Array {
private:
    T* data;       
    size_t size;   

public:
   
    Array() : data(nullptr), size(0) {}


    explicit Array(size_t n) : size(n) {
        data = new T[size](); 
    }


    Array(const Array& other) : size(other.size) {
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }

    Array& operator=(const Array& other) {
        if (this != &other) { 
            delete[] data;    
            size = other.size;
            data = new T[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    Array(Array&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; 
        other.size = 0;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void resize(size_t newSize) {
        if (newSize == size) {
            return; 
        }

        T* newData = new T[newSize]();

        size_t elementsToCopy = (newSize < size) ? newSize : size;
        std::copy(data, data + elementsToCopy, newData);

        delete[] data; 
        data = newData;
        size = newSize;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    Array<int> arr(5);


    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i) * 10;
    }

  
    std::cout << "Исходный массив: ";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    
    try {
        std::cout << "arr.at(3): " << arr.at(3) << "\n";
        std::cout << "arr.at(10): " << arr.at(10) << "\n"; 
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

   
    arr.resize(8);
    std::cout << "Массив после увеличения размера: ";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " "; 
    }
    std::cout << "\n";

    
    Array<int> arrCopy = arr;
    std::cout << "Скопированный массив: ";
    for (size_t i = 0; i < arrCopy.getSize(); ++i) {
        std::cout << arrCopy[i] << " ";
    }
    std::cout << "\n";

    return 0;
}