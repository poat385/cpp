 
#include <iostream>
#include <stdexcept>
#include <string>

// Базовый класс Shape
class Shape {
public:
    virtual std::string getDimensions() const = 0; // чистая виртуальная функция
    virtual ~Shape() = default;                    // виртуальный деструктор
};

// Класс Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус должен быть положительным числом.");
        }
    }

    std::string getDimensions() const override {
        return "Окружность с радиусом " + std::to_string(radius);
    }
};

// Класс Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Ширина и высота прямоугольника должны быть положительными числами.");
        }
    }

    std::string getDimensions() const override {
        return "Прямоугольник шириной " + std::to_string(width) + " и высотой " + std::to_string(height);
    }
};

// Класс Triangle
class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double a, double b, double c) : side1(a), side2(b), side3(c) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0 ||
            side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2) {
            throw std::invalid_argument("Строки треугольника должны быть положительны и соответствовать неравенству треугольника.");
        }
    }

    std::string getDimensions() const override {
        return "Треугольник со сторонами " + std::to_string(side1) + ", " + std::to_string(side2) + ", " + std::to_string(side3);
    }
};

// Тестовая программа
int main() {
    try {
        Circle circle(5.0);
        std::cout << circle.getDimensions() << std::endl;

        Rectangle rectangle(3.0, 4.0);
        std::cout << rectangle.getDimensions() << std::endl;

        Triangle triangle(3.0, 4.0, 5.0);
        std::cout << triangle.getDimensions() << std::endl;

        // Провоцируем исключение
        Triangle invalid_triangle(-1.0, 4.0, 5.0);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}