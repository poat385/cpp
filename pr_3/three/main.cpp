#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// 1. Custom exception class
class CustomException : public exception {
private:
    string message;
public:
    CustomException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// 2. Division function with zero division handling
double divideNumbers(double a, double b) {
    if (b == 0) {
        throw runtime_error("Деление на ноль запрещено");
    }
    return a / b;
}

// 3. Age validation function
void validateAge(int age) {
    if (age < 0 || age > 120) {
        throw out_of_range("Возраст должен быть от 0 до 120");
    }
}

// 4. Array sum function
int arraySum(const int array[], int size) {
    if (size < 0) {
        throw invalid_argument("Размер массива не может быть отрицательным");
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

// 5. Square root calculation function
double calculateSquareRoot(double number) {
    if (number < 0) {
        throw domain_error("Нельзя вычислить квадратный корень отрицательного числа");
    }
    return sqrt(number);
}

// 6. Array element search function
int findElement(const int array[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return i;
        }
    }
    throw runtime_error("Элемент не найден в массиве");
}

// 7. Divider class
class Divider {
public:
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Деление на ноль в классе Делитель");
        }
        return a / b;
    }
};

// 8. Age class
class Age {
private:
    int age;
public:
    Age(int age) : age(age) {
        if (age < 0 || age > 120) {
            throw out_of_range("Недопустимый возраст в классе Возраст");
        }
    }
    int getAge() const { return age; }
};

// 9. MyArray class
class MyArray {
private:
    int* array;
    int size;
public:
    MyArray(int size) : size(size) {
        if (size < 0) {
            throw invalid_argument("Отрицательный размер в МойМассив");
        }
        array = new int[size];
    }
    ~MyArray() { delete[] array; }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс за пределами массива в МойМассив");
        }
        return array[index];
    }

    int getSize() const { return size; }
};

// 10. Fraction class
class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw runtime_error("Знаменатель не может быть нулем в Дробь");
        }
    }
    double value() const { return static_cast<double>(numerator) / denominator; }
};

// 11. SquareRoot class
class SquareRoot {
public:
    static double calculate(double number) {
        if (number < 0) {
            throw domain_error("Отрицательное число в классе КвадратныйКорень");
        }
        return sqrt(number);
    }
};

// 12. Function for writing errors to file
void logError(const string& errorMessage) {
    ofstream errorFile("errors.log", ios::app);
    if (errorFile.is_open()) {
        errorFile << errorMessage << endl;
        errorFile.close();
    }
}

// 13. Function that calls another function and catches exception
void callingFunction() {
    try {
        divideNumbers(10, 0);
    }
    catch (const exception& e) {
        cout << "Перехвачено в вызывающейФункции: " << e.what() << endl;
        throw; // Re-throw exception
    }
}

// 14. Calculator class
class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double subtract(double a, double b) { return a - b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Деление на ноль в Калькулятор");
        }
        return a / b;
    }
};

// 15. Function for number input
int getNumberFromUser() {
    int number;
    cout << "Введите число: ";
    cin >> number;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Некорректный ввод числа");
    }
    return number;
}

// 16. Stack class
class Stack {
private:
    vector<int> data;
public:
    void push(int value) {
        data.push_back(value);
    }
    int pop() {
        if (data.empty()) {
            throw runtime_error("Попытка извлечь из пустого стека");
        }
        int value = data.back();
        data.pop_back();
        return value;
    }
};

// 17. Point class
class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {
        if (x < 0 || x > 100 || y < 0 || y > 100) {
            throw out_of_range("Координаты точки вне диапазона (0-100)");
        }
    }
    void print() const {
        cout << "Точка(" << x << ", " << y << ")" << endl;
    }
};

// 18. File reading function
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }
    string content((istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>());
    file.close();
    return content;
}

// 19. StringArray class
class StringArray {
private:
    vector<string> strings;
public:
    void addString(const string& str) {
        strings.push_back(str);
    }
    string getString(int index) const {
        if (index < 0 || index >= strings.size()) {
            throw out_of_range("Индекс за пределами массива в МассивСтрок");
        }
        return strings[index];
    }
};

// 20. Square class
class Square {
private:
    double side;
public:
    Square(double side) : side(side) {
        if (side < 0) {
            throw invalid_argument("Сторона квадрата не может быть отрицательной");
        }
    }
    double area() const { return side * side; }
};

// 21. String to number conversion function
int stringToNumber(const string& str) {
    istringstream stream(str);
    int number;
    stream >> number;
    if (stream.fail() || !stream.eof()) {
        throw runtime_error("Не удалось преобразовать строку в число: " + str);
    }
    return number;
}

// 22. FileHandler class
class FileHandler {
private:
    ifstream file;
public:
    FileHandler(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw runtime_error("Не удалось открыть файл: " + filename);
        }
    }
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }
    string readLine() {
        string line;
        getline(file, line);
        return line;
    }
};

int main() {
    
    
    cout << "\n------- Первая ------\n";
    // 1. Division by zero exception handling
    try {
        cout << "993 / 993 = " << divideNumbers(993, 993) << endl;
        cout << "993 / 0 = " << divideNumbers(993, 0) << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }
    
    cout << "\n------- Вторая ------\n";
    // 2. Age validation exception handling
    try {
        validateAge(90);
        validateAge(-9);
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }
    
    cout << "\n------- Третья ------\n";
    // 3. Array sum exception handling
    int array[] = { 1, 2, 3, 4, 5 };
    try {
        cout << "Сумма массива: " << arraySum(array, 5) << endl;
        cout << "Сумма массива: " << arraySum(array, -1) << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }
    
    cout << "\n------- Четвёртая ------\n";
    // 4. Square root exception handling
    try {
        cout << "sqrt(90) = " << calculateSquareRoot(90) << endl;
        cout << "sqrt(-90) = " << calculateSquareRoot(-90) << endl;
    }
    catch (const domain_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- ПЯТАЯ ------\n";
    // 5. Array element search exception handling
    try {
        cout << "Элемент 3 найден по индексу: " << findElement(array, 5, 3) << endl;
        cout << "Элемент 10 найден по индексу: " << findElement(array, 5, 10) << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }
    
    cout << "\n------- Шестая ------\n";
    // 6. Divider class exception handling
    try {
        cout << "Делитель: 993 / 993 = " << Divider::divide(993, 993) << endl;
        cout << "Делитель: 993 / 0 = " << Divider::divide(993, 0) << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 7 ------\n";
    // 7. Age class exception handling
    try {
        Age validAge(30);
        Age invalidAge(150);
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 8 ------\n";
    // 8. MyArray class exception handling
    try {
        MyArray myArray(5);
        myArray[0] = 10;
        cout << "myArray[0] = " << myArray[0] << endl;
        cout << "myArray[10] = " << myArray[10] << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }
    
    cout << "\n------- 9 ------\n";
    // 9. Fraction class exception handling
    try {
        Fraction validFraction(1, 2);
        Fraction invalidFraction(1, 0);
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 10 ------\n";
    // 10. SquareRoot class exception handling
    try {
        cout << "Квадратный корень из 25: " << SquareRoot::calculate(25) << endl;
        cout << "Квадратный корень из -25: " << SquareRoot::calculate(-25) << endl;
    }
    catch (const domain_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 11 ------\n";
    // 11. Multiple functions with different exceptions
    try {
        divideNumbers(10, 0);
        validateAge(150);
        calculateSquareRoot(-1);
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка времени выполнения: " << e.what() << endl;
        logError(e.what());
    }
    catch (const out_of_range& e) {
        cerr << "Выход за пределы диапазона: " << e.what() << endl;
        logError(e.what());
    }
    catch (const domain_error& e) {
        cerr << "Ошибка области определения: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 12 ------\n";
    // 12. Custom exception usage
    try {
        throw CustomException("Это пользовательское исключение");
    }
    catch (const CustomException& e) {
        cerr << "Перехвачено пользовательское исключение: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 13 ------\n";
    // 13. Exception re-throwing
    try {
        callingFunction();
    }
    catch (const exception& e) {
        cerr << "Перехвачено в main после повторного выброса: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 14 ------\n";
    // 14. Calculator class exception handling
    try {
        cout << "Калькулятор: 30 / 15 = " << Calculator::divide(30, 15) << endl;
        cout << "Калькулятор: 993 / 0 = " << Calculator::divide(993, 0) << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка калькулятора: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 15 ------\n";
    // 15. Number input exception handling
    try {
        int number = getNumberFromUser();
        cout << "Вы ввели: " << number << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка ввода: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 16 ------\n";
    // 16. Stack class exception handling
    try {
        Stack stack;
        stack.push(10);
        cout << "Извлечено из стека: " << stack.pop() << endl;
        cout << "Извлечено из стека: " << stack.pop() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка стека: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 17 ------\n";
    // 17. Point class exception handling
    try {
        Point p1(10, 20);
        p1.print();
        Point p2(-10, 150);
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка точки: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 18 ------\n";
    // 18. File reading exception handling
    try {
        string content = readFile("несуществующий.txt");
        cout << "Содержимое файла: " << content << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка файла: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 19 ------\n";
    // 19. StringArray class exception handling
    try {
        StringArray sa;
        sa.addString("HACK");
        sa.addString("ТИМОФЕЙ");
        cout << sa.getString(1) << endl;
        cout << sa.getString(5) << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка StringArray: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 20 ------\n";
    // 20. Square class exception handling
    try {
        Square sq1(5);
        cout << "Площадь квадрата: " << sq1.area() << endl;
        Square sq2(-3);
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка квадрата: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 21 ------\n";
    // 21. String to number conversion exception handling
    try {
        cout << stringToNumber("345") << endl;
        cout << stringToNumber("456п3") << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка преобразования: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 22 ------\n";
    // 22. FileHandler class exception handling
    try {
        FileHandler fh("несуществующий.txt");
        cout << fh.readLine() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка FileHandler: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n------- 23 ------\n";
    // 23. Multiple catch blocks for different exception types
    try {
        divideNumbers(10, 0);
        validateAge(150);
        calculateSquareRoot(-1);
        throw CustomException("Пример пользовательского исключения");
    }
    catch (const CustomException& e) {
        cerr << "Пользовательское исключение: " << e.what() << endl;
        logError(e.what());
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка времени выполнения: " << e.what() << endl;
        logError(e.what());
    }
    catch (const out_of_range& e) {
        cerr << "Выход за пределы диапазона: " << e.what() << endl;
        logError(e.what());
    }
    catch (const domain_error& e) {
        cerr << "Ошибка области определения: " << e.what() << endl;
        logError(e.what());
    }
    catch (...) {
        cerr << "Неизвестное исключение" << endl;
        logError("Неизвестное исключение");
    }

    return 0;
}