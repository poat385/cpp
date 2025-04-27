#include <iostream>
#include <algorithm> 
#include <memory>    

template <typename T, size_t N1, size_t N2>
std::unique_ptr<T[]> concat_arrays(const T (&arr1)[N1], const T (&arr2)[N2]) {
    std::unique_ptr<T[]> result(new T[N1 + N2]);
    
    std::copy(arr1, arr1 + N1, result.get());
    
    std::copy(arr2, arr2 + N2, result.get() + N1);
    
    return result;
}


template <typename T>
void printArray(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7};
    
    auto combined = concat_arrays(arr1, arr2);
    std::cout << "Combined array: ";
    printArray(combined.get(), 7); 

    std::string str1[] = {"DKIT", "ТИМОФЕЙ"};
    std::string str2[] = {"ДПК", "АААА"};
    
    auto combinedStr = concat_arrays(str1, str2);
    std::cout << "Combined strings: ";
    printArray(combinedStr.get(), 4); 

    return 0;
}