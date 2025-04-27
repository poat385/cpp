#include <iostream>
#include <vector>

template<typename T>
std::vector<T> arrayToVector(const T* arr, std::size_t size) {
    return std::vector<T>(arr, arr + size);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    auto vecInt = arrayToVector(numbers, sizeof(numbers)/sizeof(numbers[0]));
    
    for (const auto& num : vecInt) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    const char* strings[] = {"Hack", "Me"};
    auto vecStr = arrayToVector(strings, sizeof(strings)/sizeof(strings[0]));
    
    for (const auto& str : vecStr) {
        std::cout << str << ' ';
    }
    std::cout << '\n';

    return 0;
}