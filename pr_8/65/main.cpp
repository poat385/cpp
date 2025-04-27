 
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

// Базовый класс Shape
class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& col) : color(col) {
        if (col.empty()) {
            throw std::invalid_argument("Color cannot be empty");
        }
    }

    // Виртуальная функция получения цвета
    virtual std::string getColor() {
        if (color.empty()) {
            throw std::runtime_error("Color not set");
        }
        return color;
    }

    virtual ~Shape() = default;
};

// Класс Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& col, double r) : Shape(col), radius(r) {
        if (r <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }

    std::string getColor() override {
        // Круг может иметь только определенные цвета
        static const std::map<std::string, bool> allowedColors = {
            {"red", true}, {"blue", true}, {"green", true}, {"yellow", true}
        };

        if (allowedColors.find(color) == allowedColors.end()) {
            throw std::runtime_error("Invalid color for Circle");
        }
        return "Circle color: " + color;
    }
};

// Класс Square
class Square : public Shape {
private:
    double side;

public:
    Square(const std::string& col, double s) : Shape(col), side(s) {
        if (s <= 0) {
            throw std::invalid_argument("Side must be positive");
        }
    }

    std::string getColor() override {
        // Квадрат может быть только теплых цветов
        static const std::map<std::string, bool> warmColors = {
            {"red", true}, {"orange", true}, {"yellow", true}, {"pink", true}
        };

        if (warmColors.find(color) == warmColors.end()) {
            throw std::runtime_error("Square can only have warm colors");
        }
        return "Square color: " + color;
    }
};

// Класс Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(const std::string& col, double b, double h) 
        : Shape(col), base(b), height(h) {
        if (b <= 0 || h <= 0) {
            throw std::invalid_argument("Base and height must be positive");
        }
    }

    std::string getColor() override {
        // Треугольник может быть только холодных цветов
        static const std::map<std::string, bool> coolColors = {
            {"blue", true}, {"green", true}, {"purple", true}, {"cyan", true}
        };

        if (coolColors.find(color) == coolColors.end()) {
            throw std::runtime_error("Triangle can only have cool colors");
        }
        return "Triangle color: " + color;
    }
};

int main() {
    try {
        // Создаем фигуры с разными цветами
        Circle circle("blue", 5.0);
        Square square("red", 4.0);
        Triangle triangle("green", 3.0, 6.0);

        // Получаем и выводим цвета
        std::cout << circle.getColor() << std::endl;
        std::cout << square.getColor() << std::endl;
        std::cout << triangle.getColor() << std::endl;

        // Демонстрация обработки ошибок
        Triangle badTriangle("red", 3.0, 6.0); // Выбросит исключение
        Shape emptyShape(""); // Выбросит исключение
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}