#include <iostream>
#include <cmath>
#include <stdexcept>

template <typename T>
class Point {
public:
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}
};

template <typename T>
class Triangle {
private:
    Point<T> a, b, c;

public:
    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) : a(a), b(b), c(c) {
        if (calculateArea() == 0) {
            throw std::invalid_argument("Points are collinear, cannot form a triangle");
        }
    }

    double calculateArea() const {
        return 0.5 * std::abs(
            (a.x * (b.y - c.y)) + 
            (b.x * (c.y - a.y)) + 
            (c.x * (a.y - b.y))
        );
    }

    Point<T> getA() const { return a; }
    Point<T> getB() const { return b; }
    Point<T> getC() const { return c; }
};

int main() {
    try {
        Point<int> p1(0, 0);
        Point<int> p2(4, 0);
        Point<int> p3(0, 3);
        Triangle<int> triangleInt(p1, p2, p3);
        std::cout << "Area (int points): " << triangleInt.calculateArea() << std::endl;

        Point<double> pd1(0.0, 0.0);
        Point<double> pd2(4.5, 0.0);
        Point<double> pd3(0.0, 3.5);
        Triangle<double> triangleDouble(pd1, pd2, pd3);
        std::cout << "Area (double points): " << triangleDouble.calculateArea() << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}