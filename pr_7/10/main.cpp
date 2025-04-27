#include <iostream>
#include <type_traits> 

template <typename T>
class Complex {
    static_assert(std::is_arithmetic<T>::value, 
                  "Complex number type must be arithmetic (int, float, etc.)");

private:
    T real; 
    T imag; 

public:

    Complex() : real(0), imag(0) {}

   
    Complex(T r, T i) : real(r), imag(i) {}

    T getReal() const { return real; }
    T getImag() const { return imag; }

   
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};


int main() {
    Complex<int> a(4, 7);
    Complex<int> b(2, 6);

    Complex<int> sum = a + b;
    std::cout << a << " + " << b << " = " << sum << "\n"; // (1 + 2i) + (3 + 4i) = (4 + 6i)

    Complex<int> diff = a - b;
    std::cout << a << " - " << b << " = " << diff << "\n"; // (1 + 2i) - (3 + 4i) = (-2 + -2i)

    Complex<double> c(1.5, 2.5);
    Complex<double> d(0.5, 1.5);
    std::cout << c << " + " << d << " = " << (c + d) << "\n"; // (1.5 + 2.5i) + (0.5 + 1.5i) = (2 + 4i)

    return 0;
}