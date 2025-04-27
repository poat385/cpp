#include <iostream>
#include <cmath>
#include <stdexcept>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }
    
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Width and height must be positive");
        }
    }
    
    double getArea() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw std::invalid_argument("All sides must be positive");
        }
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw std::invalid_argument("Triangle inequality violated");
        }
    }
    
    double getArea() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    try {
        Circle c(5.0);
        std::cout << "Circle area: " << c.getArea() << std::endl;
        
        Rectangle r(4.0, 6.0);
        std::cout << "Rectangle area: " << r.getArea() << std::endl;
        
        Triangle t(3.0, 4.0, 5.0);
        std::cout << "Triangle area: " << t.getArea() << std::endl;
        
        // This will throw an exception
        // Circle invalid_c(-1.0);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}