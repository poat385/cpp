#include <iostream>
#include <stdexcept>
#include <vector>

struct Point {
    double x, y;
};

// Минимальный прямоугольник, представляющий bounding-box
struct BoundingBox {
    double min_x, max_x, min_y, max_y;
};

// Базовый класс Shape
class Shape {
public:
    virtual ~Shape() = default;

    // Получить bounding-box фигуры
    virtual BoundingBox getBoundingBox() const = 0;
};

// Класс Circle
class Circle : public Shape {
private:
    Point center;       // Центр круга
    double radius;      // Радиус круга

public:
    Circle(Point center, double radius) : center(center), radius(radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус круга должен быть положительным.");
        }
    }

    BoundingBox getBoundingBox() const override {
        return {
            center.x - radius, center.x + radius,
            center.y - radius, center.y + radius
        };
    }
};

// Класс Polygon
class Polygon : public Shape {
private:
    std::vector<Point> vertices; // Вершины многоугольника

public:
    Polygon(const std::vector<Point>& points) : vertices(points) {
        if (points.empty()) {
            throw std::invalid_argument("Многоугольник должен иметь хотя бы одну вершину.");
        }
    }

    BoundingBox getBoundingBox() const override {
        if (vertices.empty()) {
            throw std::invalid_argument("Нет вершин у многоугольника.");
        }

        double min_x = vertices.front().x, max_x = vertices.front().x;
        double min_y = vertices.front().y, max_y = vertices.front().y;

        for (const auto& point : vertices) {
            min_x = std::min(min_x, point.x);
            max_x = std::max(max_x, point.x);
            min_y = std::min(min_y, point.y);
            max_y = std::max(max_y, point.y);
        }

        return {min_x, max_x, min_y, max_y};
    }
};

// Демонстрационный пример
int main() {
    try {
        Circle circle({0, 0}, 5);
        auto bbox_circle = circle.getBoundingBox();
        std::cout << "Ограничивающий прямоугольник круга: "
                 << "(" << bbox_circle.min_x << "," << bbox_circle.min_y << ") to ("
                 << bbox_circle.max_x << "," << bbox_circle.max_y << ")\n";

        std::vector<Point> polygon_vertices = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
        Polygon polygon(polygon_vertices);
        auto bbox_polygon = polygon.getBoundingBox();
        std::cout << "Ограничивающий прямоугольник многоугольника: "
                 << "(" << bbox_polygon.min_x << "," << bbox_polygon.min_y << ") to ("
                 << bbox_polygon.max_x << "," << bbox_polygon.max_y << ")\n";
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}