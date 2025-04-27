#include <iostream>
using namespace std;

template <typename T>
struct TwoValues {
    T first;
    T second;
};

template <typename T>
TwoValues<T> swap(T a, T b) {
    return {b, a};
}

int main() {
    auto result = swap(11, -4);
    auto result_char = swap('r', 'c');

    cout << result.first << " " << result.second << endl;  
    cout << result_char.first << " " << result_char.second;  
    
    return 0;
}