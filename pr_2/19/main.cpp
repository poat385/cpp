#include <iostream>
#include <vector>
#include <algorithm> 

template <typename T, size_t N, typename Predicate>
std::vector<T> filter_array(const T (&arr)[N], Predicate predicate) {
    std::vector<T> result;
    
    for (size_t i = 0; i < N; ++i) {
        if (predicate(arr[i])) {
            result.push_back(arr[i]);
        }
    }
    

    return result;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto isEven = [](int x) { return x % 2 == 0; };
    auto evenNumbers = filter_array(numbers, isEven);
    
    std::cout << "Even numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::string words[] = {"cat", "dog", "elephant", "fox", "banditoBobrito"};
    auto isLongWord = [](const std::string& s) { return s.length() > 3; };
    auto longWords = filter_array(words, isLongWord);
    
    std::cout << "Long words: ";
    for (const auto& word : longWords) {
        std::cout << word << " ";
    }
    std::cout << "\n";

    return 0;
}