#include <iostream>
#include <stdexcept>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

class Ellipse : public Shape {
private:
    double majorAxis_; 
    double minorAxis_; 

public:
    Ellipse(double majorAxis, double minorAxis) :
        majorAxis_(majorAxis), minorAxis_(minorAxis) {
        if (majorAxis <= 0 || minorAxis <= 0) {
            throw std::invalid_argument("Параметры эллипса должны быть положительными.");
        }
    }

    double getArea() const override {
        return M_PI * majorAxis_ * minorAxis_;
    }
};

class Square : public Shape {
private:
    double side_; 

public:
    Square(double side) : side_(side) {
        if (side <= 0) {
            throw std::invalid_argument("Сторона квадрата должна быть положительной.");
        }
    }

    double getArea() const override {
        return side_ * side_;
    }
};

int main() {
    try {
        Ellipse ellipse(5, 3);
        std::cout << "Площадь эллипса: " << ellipse.getArea() << std::endl;

        Square square(4);
        std::cout << "Площадь квадрата: " << square.getArea() << std::endl;

        Ellipse wrongEllipse(-1, 2); 
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}