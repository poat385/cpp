#include <iostream>
#include <stdexcept>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void reflect(double angle) = 0;
};

class Circle : public Shape {
public:
    void reflect(double angle) override {
        if(angle < 0 || angle > 360){
            throw std::invalid_argument("Некорректный угол поворота");
        }
        std::cout << "Окружность отражена на угол " << angle << " градусов." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void reflect(double angle) override {
        if(angle < 0 || angle > 360){
            throw std::invalid_argument("Некорректный угол поворота");
        }
        std::cout << "Прямоугольник отражен на угол " << angle << " градусов." << std::endl;
    }
};

int main() {
    try{
        Circle circle;
        circle.reflect(90);

        Rectangle rect;
        rect.reflect(450); 
    } catch(const std::exception& e){
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}