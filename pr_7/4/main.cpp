#include <iostream>

template <typename T>
class Point {
private:
    T x;
    T y;

public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }

    T getX() const { return x; }
    T getY() const { return y; }
};

int main() {

    Point<int> p1(1, 2);
    Point<int> p2(3, 4);

    Point<int> sum = p1 + p2;
    Point<int> diff = p1 - p2;

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Разность: " << diff << std::endl;

    Point<double> p3(1.5, 2.5);
    Point<double> p4(0.5, 1.5);

    std::cout << "\nС double:" << std::endl;
    std::cout << "p3 + p4: " << (p3 + p4) << std::endl;
    std::cout << "p3 - p4: " << (p3 - p4) << std::endl;

    return 0;
}