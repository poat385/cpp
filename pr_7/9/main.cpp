#include <iostream>

template <typename T>
bool are_equal(const T& a, const T& b) {
    return a == b;
}

// Пример использования
int main() {
    int x = 993, y = 993;
    std::cout << std::boolalpha; 
    std::cout << "993 и 993 " << are_equal(x, y) << "\n"; 

    double d1 = 9.33, d2 = 3.99;
    std::cout << "9.33 и 3.99: " << are_equal(d1, d2) << "\n";

    std::string s1 = "hack", s2 = "me";
    std::cout << "hack и me " << are_equal(s1, s2) << "\n"; 

    return 0;
}