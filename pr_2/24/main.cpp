#include <iostream>

template<typename T>
class Cube {
private:
    T edgeLength;   

public:
    explicit Cube(T length) : edgeLength(length) {}

    T volume() const {
        return edgeLength * edgeLength * edgeLength;
    }

    T surfaceArea() const {
        return 6 * edgeLength * edgeLength;
    }

    T getEdgeLength() const {
        return edgeLength;
    }
};

int main() {
    Cube<int> cube1(5);     
    std::cout << "Объем куба (int): " << cube1.volume() << "\n";
    std::cout << "Площадь поверхности куба (int): " << cube1.surfaceArea() << "\n\n";

    Cube<double> cube2(3.5);  
    std::cout << "Объем куба (double): " << cube2.volume() << "\n";
    std::cout << "Площадь поверхности куба (double): " << cube2.surfaceArea() << "\n";

    return 0;
}