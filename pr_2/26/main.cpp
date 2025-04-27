#include <iostream>

template<typename T>
class Wrapper {
private:
    T value_;      

public:
    Wrapper(const T& initial_value) : value_(initial_value) {}

    T getValue() const {
        return value_;
    }

    void setValue(const T& new_value) {
        value_ = new_value;
    }
};

int main() {
    Wrapper<int> wrapper_int(42);
    std::cout << "Initial integer value: " << wrapper_int.getValue() << std::endl;
    wrapper_int.setValue(100);
    std::cout << "Updated integer value: " << wrapper_int.getValue() << std::endl;
    std::cout << "\n";
    Wrapper<std::string> wrapper_string("Hello");
    std::cout << "Initial string value: " << wrapper_string.getValue() << std::endl;
    wrapper_string.setValue("World!");
    std::cout << "Updated string value: " << wrapper_string.getValue() << std::endl;

    return 0;
} 