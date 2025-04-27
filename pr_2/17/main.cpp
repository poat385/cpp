#include <iostream>
#include <numeric> 
#include <type_traits> 

template <typename T, size_t N>
double calculate_average(const T (&arr)[N]) {
    static_assert(std::is_arithmetic<T>::value, 
                 "Элементы массива должны быть числового типа (int, float, double и т.д.)");

    double sum = std::accumulate(arr, arr + N, 0.0);
    
    return sum / N;
}

template <typename T, size_t N>
double calculate_averageManual(const T (&arr)[N]) {
    static_assert(std::is_arithmetic<T>::value, 
                 "Элементы массива должны быть числового типа");
    
    double sum = 0.0;
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }
    return sum / N;
}

int main() {
    int intArray[] = {10, 20, 30, 40, 50};
    std::cout << "Среднее значение массива int: " 
              << calculate_average(intArray) << "\n";

    double doubleArray[] = {1.5, 2.5, 3.5, 4.5};
    std::cout << "Среднее значение массива double: " 
              << calculate_average(doubleArray) << "\n"; 

    char charArray[] = {10, 20, 30};
    std::cout << "Среднее значение массива char: " 
              << calculate_average(charArray) << "\n"; 

    return 0;
}