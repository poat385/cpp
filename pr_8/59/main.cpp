#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

// Базовый класс Shape
class Shape {
public:
    virtual double getPerimeter() const {
        throw std::runtime_error("Cannot calculate perimeter for base Shape class");
    }
    
    virtual ~Shape() {} // Виртуальный деструктор
};

// Класс Circle (круг)
class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Circle radius must be positive");
        }
    }
    
    double getPerimeter() const override {
        return 2 * M_PI * radius_;
    }

private:
    double radius_;
};

// Класс Rectangle (прямоугольник)
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Rectangle sides must be positive");
        }
    }
    
    double getPerimeter() const override {
        return 2 * (width_ + height_);
    }

private:
    double width_;
    double height_;
};

// Класс Triangle (треугольник)
class Triangle : public Shape {
public:
    Triangle(double a, double b, double c) : sides_{a, b, c} {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw std::invalid_argument("Triangle sides must be positive");
        }
        
        // Проверка неравенства треугольника
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw std::invalid_argument("Triangle inequality violation");
        }
    }
    
    double getPerimeter() const override {
        return sides_[0] + sides_[1] + sides_[2];
    }

private:
    std::vector<double> sides_;
};

// Функция для тестирования фигур
void testShape(const Shape* shape) {
    try {
        double perimeter = shape->getPerimeter();
        std::cout << "Perimeter: " << perimeter << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    // Тестирование корректных фигур
    std::cout << "=== Testing valid shapes ===" << std::endl;
    try {
        Circle circle(5.0);
        testShape(&circle);
        
        Rectangle rectangle(4.0, 6.0);
        testShape(&rectangle);
        
        Triangle triangle(3.0, 4.0, 5.0);
        testShape(&triangle);
    } catch (const std::exception& e) {
        std::cerr << "Construction error: " << e.what() << std::endl;
    }
    
    // Тестирование некорректных фигур
    std::cout << "\n=== Testing invalid shapes ===" << std::endl;
    try {
        Circle badCircle(-1.0); // Отрицательный радиус
        testShape(&badCircle);
    } catch (const std::exception& e) {
        std::cerr << "Construction error: " << e.what() << std::endl;
    }
    
    try {
        Rectangle badRectangle(4.0, -2.0); // Отрицательная высота
        testShape(&badRectangle);
    } catch (const std::exception& e) {
        std::cerr << "Construction error: " << e.what() << std::endl;
    }
    
    try {
        Triangle badTriangle(1.0, 1.0, 3.0); // Нарушение неравенства треугольника
        testShape(&badTriangle);
    } catch (const std::exception& e) {
        std::cerr << "Construction error: " << e.what() << std::endl;
    }
    
    return 0;
}