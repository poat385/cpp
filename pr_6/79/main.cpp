 
#include <iostream>
#include <stdexcept>
#include <cmath>

// Базовый класс Shape
class Shape {
public:
    virtual ~Shape() = default;

    // Виртуальная функция расчета площади, выбрасывающая исключение при некорректных значениях
    virtual double getArea() const {
        throw std::logic_error("Ошибка: неизвестная форма фигуры.");
    }
};

// Класс Circle (окружность)
class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double rad) : radius(rad) {
        if (rad <= 0) {
            throw std::invalid_argument("Радиус окружности должен быть положительным числом.");
        }
    }

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// Класс Rectangle (прямоугольник)
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw std::invalid_argument("Ширина и высота прямоугольника должны быть положительными числами.");
        }
    }

    double getArea() const override {
        return width * height;
    }
};

// Класс Triangle (треугольник)
class Triangle : public Shape {
private:
    double a, b, c; // Стороны треугольника

public:
    Triangle(double A, double B, double C) : a(A), b(B), c(C) {
        if (A <= 0 || B <= 0 || C <= 0) {
            throw std::invalid_argument("Все стороны треугольника должны быть положительными числами.");
        }
        if ((a >= b + c) || (b >= a + c) || (c >= a + b)) {
            throw std::invalid_argument("Сумма любых двух сторон должна быть больше третьей стороны.");
        }
    }

    double getArea() const override {
        double p = (a + b + c) / 2.0; // Полупериметр
        return std::sqrt(p * (p - a) * (p - b) * (p - c)); // Формула Герона
    }
};

int main() {
    try {
        // Примеры правильных объектов
        Circle circ(5.0);
        Rectangle rect(4.0, 6.0);
        Triangle trian(3.0, 4.0, 5.0);

        std::cout << "Площадь круга: " << circ.getArea() << std::endl;
        std::cout << "Площадь прямоугольника: " << rect.getArea() << std::endl;
        std::cout << "Площадь треугольника: " << trian.getArea() << std::endl;

        // Некорректные объекты
        Circle wrongCirc(-5.0);       // Радиус отрицателен
        Rectangle wrongRect(-4.0, 6.0); // Ширина отрицательна
        Triangle wrongTriang(1.0, 2.0, 5.0); // Невозможный треугольник
    } catch (const std::exception& ex) {
        std::cerr << "Исключение: " << ex.what() << std::endl;
    }

    return 0;
}