#include <iostream>
#include <stdexcept>

class Shape {
protected:
    double x_, y_; 

public:
    Shape(double x, double y) : x_(x), y_(y) {} 

    virtual ~Shape() = default;

    virtual void translate(double dx, double dy) {
        if (!isValidPosition(x_ + dx, y_ + dy)) {
            throw std::invalid_argument("Недопустимая позиция фигуры.");
        }
        x_ += dx;
        y_ += dy;
    }

    virtual bool isValidPosition(double x, double y) const {
        return true;
    }

    double getX() const { return x_; }
    double getY() const { return y_; }
};

class Circle : public Shape {
private:
    double radius_;

public:
    Circle(double x, double y, double radius) : Shape(x, y), radius_(radius) {}

    void translate(double dx, double dy) override {
        if (!isValidPosition(getX() + dx, getY() + dy)) {
            throw std::invalid_argument("Невозможно переместить круг на указанные координаты.");
        }
        Shape::translate(dx, dy); 
    }

    bool isValidPosition(double x, double y) const override {
        return ((x >= radius_) && (x <= 100 - radius_) &&
               (y >= radius_) && (y <= 100 - radius_));
    }

    double getRadius() const { return radius_; }
};

class Rectangle : public Shape {
private:
    double width_, height_; 

public:
    Rectangle(double x, double y, double width, double height) : Shape(x, y), width_(width), height_(height) {}

    void translate(double dx, double dy) override {
        if (!isValidPosition(getX() + dx, getY() + dy)) {
            throw std::invalid_argument("Невозможно переместить прямоугольник на указанные координаты.");
        }
        Shape::translate(dx, dy); 
    }

    bool isValidPosition(double x, double y) const override {
        return ((x >= 0) && (x + width_ <= 100) &&
               (y >= 0) && (y + height_ <= 100));
    }

    double getWidth() const { return width_; }
    double getHeight() const { return height_; }
};

// Точка входа
int main() {
    try {
        Circle circle(50, 50, 10);
        circle.translate(-50, 0); 

        Rectangle rectangle(20, 20, 20, 20);
        rectangle.translate(80, 80); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}