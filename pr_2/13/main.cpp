#include <iostream>
#include <string>

template <typename T, size_t N>
int findIndex(const T (&arr)[N], const T& value) {
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1; // Если элемент не найден
}

// Пример использования
int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    std::string words[] = {"hack", "me", "please"};

    // Поиск в массиве чисел
    int index1 = findIndex(numbers, 30);
    std::cout << "Index of 30: " << index1 << "\n"; // 2

    // Поиск в массиве строк
    int index2 = findIndex(words, std::string("me"));
    std::cout << "Index of 'me': " << index2 << "\n"; // 1

    // Элемент не найден
    int index3 = findIndex(numbers, 99);
    std::cout << "Index of 99: " << index3 << "\n"; // -1

    return 0;
}