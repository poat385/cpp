#include <iostream>
#include <stdexcept>
#include <cmath>

// Базовый абстрактный класс Shape
class Shape {
public:
    virtual ~Shape() = default;
    
    // Метод вычисления пересечения фигур
    virtual void getIntersection(const Shape& other) const {
        throw std::runtime_error("Ошибка! Некорректные параметры.");
    }
};

// Класс круга
class Circle : public Shape {
private:
    double radius_;
    double x_, y_; // координаты центра

public:
    Circle(double r, double x, double y)
        : radius_(r), x_(x), y_(y) {}

    bool intersectsWithCircle(const Circle& other) const {
        double dx = this->x_ - other.x_;
        double dy = this->y_ - other.y_;
        return sqrt(dx * dx + dy * dy) <= (this->radius_ + other.radius_);
    }

    void getIntersection(const Shape& other) const override {
        if (const auto* circle = dynamic_cast<const Circle*>(&other)) {
            if (!intersectsWithCircle(*circle))
                throw std::runtime_error("Круги не пересекаются!");
            
            std::cout << "Пересечение кругов успешно найдено.\n";
        } else {
            throw std::runtime_error("Некорректная фигура для операции пересечения.");
        }
    }
};

// Класс прямоугольника
class Rectangle : public Shape {
private:
    double width_, height_;
    double x_, y_; // координаты левого верхнего угла

public:
    Rectangle(double w, double h, double x, double y)
        : width_(w), height_(h), x_(x), y_(y) {}

    bool intersectsWithRectangle(const Rectangle& other) const {
        return !(this->x_ > other.x_ + other.width_
              || this->x_ + this->width_ < other.x_
              || this->y_ > other.y_ + other.height_
              || this->y_ + this->height_ < other.y_);
    }

    void getIntersection(const Shape& other) const override {
        if (const auto* rect = dynamic_cast<const Rectangle*>(&other)) {
            if (!intersectsWithRectangle(*rect))
                throw std::runtime_error("Прямоугольники не пересекаются!");
                
            std::cout << "Пересечение прямоугольников успешно найдено.\n";
        } else {
            throw std::runtime_error("Некорректная фигура для операции пересечения.");
        }
    }
};

// Класс многоугольника
class Polygon : public Shape {
private:
    int numSides_;
    double sideLength_;
    double x_, y_; // координаты центральной точки

public:
    Polygon(int n, double s, double x, double y)
        : numSides_(n), sideLength_(s), x_(x), y_(y) {}

    bool intersectsWithPolygon(const Polygon& other) const {
        // Здесь реализована простая проверка расстояния центров,
        // реальная реализация должна учитывать форму и ориентацию многоугольников
        double dist = hypot(x_ - other.x_, y_ - other.y_);
        return dist < sideLength_ + other.sideLength_;
    }

    void getIntersection(const Shape& other) const override {
        if (const auto* poly = dynamic_cast<const Polygon*>(&other)) {
            if (!intersectsWithPolygon(*poly))
                throw std::runtime_error("Многоугольники не пересекаются!");
        
            std::cout << "Пересечение многоугольников успешно найдено.\n";
        } else {
            throw std::runtime_error("Некорректная фигура для операции пересечения.");
        }
    }
};

int main() {
    try {
        Circle c1(5, 0, 0);
        Circle c2(7, 8, 0); // Непересекающиеся круги
        c1.getIntersection(c2); // Выбросит ошибку
    } catch (std::exception &ex) {
        std::cerr << ex.what() << "\n";
    }

    try {
        Rectangle r1(5, 5, 0, 0);
        Rectangle r2(5, 5, 3, 3); // Пересекающиеся прямоугольники
        r1.getIntersection(r2); // Успешно найдет пересечение
    } catch (std::exception &ex) {
        std::cerr << ex.what() << "\n";
    }

    return 0;
}