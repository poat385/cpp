#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    bool swapped;
    int n = arr.size();
    do {
        swapped = false;
        for(int i = 1; i < n; ++i) {
            if(arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }

        --n;
    } while(swapped);
}

template<typename T>
void printArray(const std::vector<T>& arr) {
    for(const auto& item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {356, 34, 993, 58, 789, 2, 0};
    std::cout << "Исходный массив:\n";
    printArray(arr);

    bubbleSort(arr);

    std::cout << "Отсортированный массив:\n";
    printArray(arr);

    return 0;
}