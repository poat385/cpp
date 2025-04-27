#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> intersection(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> result;

    std::vector<T> temp_v1(v1.begin(), v1.end());
    std::vector<T> temp_v2(v2.begin(), v2.end());

    std::sort(temp_v1.begin(), temp_v1.end());
    std::sort(temp_v2.begin(), temp_v2.end());

    std::set_intersection(
        temp_v1.begin(), temp_v1.end(),
        temp_v2.begin(), temp_v2.end(),
        std::back_inserter(result)
    );

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 4, 5, 6, 7};

    auto result = intersection(arr1, arr2);

    std::cout << "Пересечение массивов: ";
    for (auto elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}