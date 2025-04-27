#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {

    int result = max(65, 993);
    std::cout << result << std::endl;

    double dresult = max(0.234, 4.43);
    std::cout << dresult << std::endl;

    char cresult = max('t', 'q');
    std::cout << cresult << std::endl;


    return 0;
}