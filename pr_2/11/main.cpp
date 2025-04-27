#include <iostream>
#include <algorithm> 

template <typename T, size_t N>
void reverseArray(T (&arr)[N]) {
    size_t start = 0;
    size_t end = N - 1;
    
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

template <typename T, size_t N>
void printArray(const T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    printArray(intArr);
    
    reverseArray(intArr);
    std::cout << "Reversed int array: ";
    printArray(intArr);

    // Пример со строками
    std::string strArr[] = {"hack", "me", "please", "DKIT", "ТИМОФЕЙ"};
    std::cout << "Original string array: ";
    printArray(strArr);
    
    reverseArray(strArr);
    std::cout << "Reversed string array: ";
    printArray(strArr);

    return 0;
}