#include <iostream>
#include <stdexcept>
#include <string>

// Базовый класс Shape
class Shape {
public:
    virtual std::string getDescription() const = 0; // Чистая виртуальная функция
    virtual ~Shape() = default;                     // Виртуальный деструктор
};

// Производный класс Circle
class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double rad) : radius(rad) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус окружности должен быть положительным числом.");
        }
    }

    std::string getDescription() const override {
        return "Окружность с радиусом " + std::to_string(radius);
    }
};

// Производный класс Square
class Square : public Shape {
private:
    double side;

public:
    explicit Square(double len) : side(len) {
        if (side <= 0) {
            throw std::invalid_argument("Длины сторон квадрата должны быть положительными числами.");
        }
    }

    std::string getDescription() const override {
        return "Квадрат со стороной " + std::to_string(side);
    }
};

// Производный класс Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {
        if (base <= 0 || height <= 0) {
            throw std::invalid_argument("Основание и высота треугольника должны быть положительными числами.");
        }
    }

    std::string getDescription() const override {
        return "Треугольник с основанием " + std::to_string(base) +
               " и высотой " + std::to_string(height);
    }
};

// Тестовый пример
int main() {
    try {
        Circle circle(5.0);
        std::cout << circle.getDescription() << std::endl;

        Square square(3.0);
        std::cout << square.getDescription() << std::endl;

        Triangle triangle(4.0, 6.0);
        std::cout << triangle.getDescription() << std::endl;

        // Пробуем передать некорректные параметры
        Circle invalid_circle(-1.0); // Должно вызвать исключение
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}