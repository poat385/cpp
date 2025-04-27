#include <iostream>
#include <stdexcept>

// Базовый класс Shape
class Shape {
public:
    virtual void transform(double param) = 0; // Чистая виртуальная функция
};

// Класс Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    void transform(double newRadius) override {
        if (newRadius <= 0) {
            throw std::invalid_argument("Радиус должен быть положительным числом");
        }
        radius = newRadius;
        std::cout << "Круг трансформирован успешно. Новый радиус: " << radius << "\n";
    }
};

// Класс Square
class Square : public Shape {
private:
    double sideLength;
    
public:
    Square(double s) : sideLength(s) {}
    
    void transform(double newSide) override {
        if (newSide <= 0) {
            throw std::invalid_argument("Длина стороны должна быть положительной");
        }
        sideLength = newSide;
        std::cout << "Квадрат трансформирован успешно. Новая сторона: " << sideLength << "\n";
    }
};

// Класс Polygon
class Polygon : public Shape {
private:
    int numVertices;
    double minEdgeSize;
    
public:
    Polygon(int vertices, double edgeSize)
        : numVertices(vertices), minEdgeSize(edgeSize) {}
        
    // Переопределение метода в соответствии с требованием одного параметра
    void transform(double newParam) override {
        // Интерпретация нового параметра зависит от конкретного контекста,
        // например, уменьшаем/увеличиваем вершины пропорционально новому значению
        if (numVertices * newParam < 3 || newParam <= 0) {
            throw std::invalid_argument("Недопустимое значение изменения вершин");
        }
        numVertices *= static_cast<int>(newParam); // Округляем до целого числа
        std::cout << "Многоугольник трансформирован успешно. Количество вершин обновлено.\n";
    }
};

// Тестируем классы
int main() {
    try {
        Circle circle(5);
        circle.transform(-1); // Ошибка: радиус меньше нуля
    } catch(const std::exception& e) {
        std::cerr << "Ошибка при трансформации круга: " << e.what() << '\n';
    }

    try {
        Square square(7);
        square.transform(8); // Успешная трансформация квадрата
    } catch(const std::exception& e) {
        std::cerr << "Ошибка при трансформации квадрата: " << e.what() << '\n';
    }

    try {
        Polygon polygon(6, 3);
        polygon.transform(2); // Попытка увеличить число вершин вдвое
    } catch(const std::exception& e) {
        std::cerr << "Ошибка при трансформации многоугольника: " << e.what() << '\n';
    }

    return 0;
}