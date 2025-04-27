#include <iostream>
#include <stdexcept>

class Shape {
public:
    virtual ~Shape() = default;

    virtual double getPerimeter() const = 0;
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
        validateSides(); 
    }

    double getPerimeter() const override {
        return sideA + sideB + sideC;
    }

private:
    void validateSides() const {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0 ||
            sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA) {
            throw std::invalid_argument("Некорректные параметры треугольника.");
        }
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        validateSide(); 
    }

    double getPerimeter() const override {
        return 4 * side;
    }

private:
    void validateSide() const {
        if (side <= 0) {
            throw std::invalid_argument("Некорректная сторона квадрата.");
        }
    }
};
int main() {
    try {
        Triangle triangle(3, 4, 5);
        std::cout << "Периметр треугольника: " << triangle.getPerimeter() << std::endl;

        Square square(5);
        std::cout << "Периметр квадрата: " << square.getPerimeter() << std::endl;

        Triangle invalidTriangle(1, 2, 5);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}