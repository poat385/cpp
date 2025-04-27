#include <iostream>
#include <vector>
#include <stdexcept> 

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols));
    }

    Matrix(size_t rows, size_t cols, const T& initValue) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols, initValue));
    }

    T& operator()(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Индексы матрицы выходят за границы");
        }
        return data[row][col];
    }

    const T& operator()(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Индексы матрицы выходят за границы");
        }
        return data[row][col];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Размеры матриц должны совпадать для сложения");
        }
        
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Размеры матриц должны совпадать для вычитания");
        }
        
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] - other(i, j);
            }
        }
        return result;
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Matrix<int> mat1(2, 3, 1);
    Matrix<int> mat2(2, 3, 2);

    mat1(0, 0) = 5;
    mat2(1, 2) = 10;

    std::cout << "Матрица 1:\n";
    mat1.print();
    std::cout << "\nМатрица 2:\n";
    mat2.print();

    Matrix<int> sum = mat1 + mat2;
    std::cout << "\nСумма:\n";
    sum.print();

    Matrix<int> diff = mat1 - mat2;
    std::cout << "\nРазность:\n";
    diff.print();

    try {
        Matrix<int> mat3(3, 3);
        Matrix<int> invalid = mat1 + mat3; 
    } catch (const std::invalid_argument& e) {
        std::cerr << "\nОшибка: " << e.what() << "\n";
    }

    return 0;
}