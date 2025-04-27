#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm> // Добавлено для std::find

// 1.
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r < 0) throw std::invalid_argument("Radius cannot be negative");
    }
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w < 0 || h < 0) throw std::invalid_argument("Sides cannot be negative");
    }
    double area() const override { return width * height; }
};

// 2.
class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
    std::string name;
public:
    Dog(const std::string& n) : name(n) {
        if (n.empty()) throw std::invalid_argument("Плохое имя");
    }
    void speak() const override { std::cout << "Имя " << name << std::endl; }
};

class Cat : public Animal {
    std::string name;
public:
    Cat(const std::string& n) : name(n) {
        if (n.empty()) throw std::invalid_argument("Плохое имя");
    }
    void speak() const override { std::cout << "мяяяя! Имя " << name << std::endl; }
};

// 3.
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    virtual void withdraw(double amount) {
        if (amount > balance) throw std::runtime_error("Insufficient balance");
        balance -= amount;
    }
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override {
        if (amount > 10000) throw std::runtime_error("Savings account withdrawal limit exceeded");
        BankAccount::withdraw(amount);
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override {
        if (amount > 5000) throw std::runtime_error("Checking account withdrawal limit exceeded");
        BankAccount::withdraw(amount);
    }
};

// 4.
class FileHandler {
public:
    virtual void open(const std::string& filename) = 0;
    virtual ~FileHandler() {}
};

class TextFileHandler : public FileHandler {
public:
    void open(const std::string& filename) override {
        std::ifstream file(filename);
        if (!file) throw std::runtime_error("Ошибка, текст не найден: " + filename);
        std::cout << "Text file opened: " << filename << std::endl;
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void open(const std::string& filename) override {
        std::ifstream file(filename, std::ios::binary);
        if (!file) throw std::runtime_error("Binary file not found: " + filename);
        std::cout << "Binary file opened: " << filename << std::endl;
    }
};

// 5.
class DrawableShape {
public:
    virtual void draw() const = 0;
    virtual ~DrawableShape() {}
};

class Triangle : public DrawableShape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw std::invalid_argument("Invalid triangle sides");
    }
    void draw() const override { std::cout << "Drawing triangle with sides " << a << ", " << b << ", " << c << std::endl; }
};

class Square : public DrawableShape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw std::invalid_argument("Square side must be positive");
    }
    void draw() const override { std::cout << "Drawing square with side " << side << std::endl; }
};

// 6.
class Person {
public:
    virtual void display() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
    std::string name;
    int age;
public:
    Student(const std::string& n, int a) : name(n), age(a) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
        if (a < 5 || a > 120) throw std::invalid_argument("Invalid age");
    }
    void display() const override {
        std::cout << "Student: " << name << ", Age: " << age << std::endl;
    }
};

class Teacher : public Person {
    std::string name;
    int age;
public:
    Teacher(const std::string& n, int a) : name(n), age(a) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
        if (a < 21 || a > 120) throw std::invalid_argument("Invalid age");
    }
    void display() const override {
        std::cout << "Teacher: " << name << ", Age: " << age << std::endl;
    }
};

// 7.
class Calculator {
public:
    virtual double calculate(double a, double b) const = 0;
    virtual ~Calculator() {}
};

class Addition : public Calculator {
public:
    double calculate(double a, double b) const override { return a + b; }
};

class Division : public Calculator {
public:
    double calculate(double a, double b) const override {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
};

// 8.
class Game {
public:
    virtual void start() = 0;
    virtual ~Game() {}
};

class Chess : public Game {
public:
    void start() override {
        std::cout << "Chess game started" << std::endl;
    }
};

class Tennis : public Game {
    int players;
public:
    Tennis(int p) : players(p) {
        if (p != 2 && p != 4) throw std::invalid_argument("Tennis requires 2 or 4 players");
    }
    void start() override {
        std::cout << "Tennis game started with " << players << " players" << std::endl;
    }
};

// 9.
class Document {
public:
    virtual void save(const std::string& filename) = 0;
    virtual ~Document() {}
};

class PDFDocument : public Document {
public:
    void save(const std::string& filename) override {
        if (filename.empty()) throw std::runtime_error("Filename cannot be empty");

        // Проверка расширения файла вручную:
        size_t pos = filename.rfind('.');
        if (pos == std::string::npos || filename.substr(pos) != ".pdf")
            throw std::runtime_error("PDF filename must end with .pdf");

        std::cout << "PDF document saved as " << filename << std::endl;
    }
};

class WordDocument : public Document {
public:
    void save(const std::string& filename) override {
        if (filename.empty()) throw std::runtime_error("Filename cannot be empty");

        // Проверка расширения файла вручную:
        size_t pos = filename.rfind('.');
        if (pos == std::string::npos || filename.substr(pos) != ".docx")
            throw std::runtime_error("Word filename must end with .docx");

        std::cout << "Word document saved as " << filename << std::endl;
    }
};

// 10.
class Matrix {
protected:
    int rows, cols;
public:
    Matrix(int r, int c) : rows(r), cols(c) {}
    virtual double getElement(int r, int c) const = 0;
    virtual ~Matrix() {}
};

class IntMatrix : public Matrix {
    std::vector<std::vector<int>> data;
public:
    IntMatrix(int r, int c) : Matrix(r, c), data(r, std::vector<int>(c)) {}
    double getElement(int r, int c) const override {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("Matrix index out of range");
        return data[r][c];
    }
};

class FloatMatrix : public Matrix {
    std::vector<std::vector<float>> data;
public:
    FloatMatrix(int r, int c) : Matrix(r, c), data(r, std::vector<float>(c)) {}
    double getElement(int r, int c) const override {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("Matrix index out of range");
        return data[r][c];
    }
};

// 11.
class Vehicle {
public:
    virtual double fuelEfficiency() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    double mpg;
public:
    Car(double m) : mpg(m) {
        if (m <= 0) throw std::invalid_argument("MPG must be positive");
    }
    double fuelEfficiency() const override { return mpg; }
};

class Truck : public Vehicle {
    double mpg;
public:
    Truck(double m) : mpg(m) {
        if (m <= 0) throw std::invalid_argument("MPG must be positive");
    }
    double fuelEfficiency() const override { return mpg; }
};

// 12.
class User {
public:
    virtual void login(const std::string& username, const std::string& password) = 0;
    virtual ~User() {}
};

class AdminUser : public User {
public:
    void login(const std::string& username, const std::string& password) override {
        if (username.empty() || password.empty()) throw std::invalid_argument("Username and password cannot be empty");
        if (password != "admin123") throw std::runtime_error("Invalid admin password");
        std::cout << "Admin logged in: " << username << std::endl;
    }
};

class RegularUser : public User {
public:
    void login(const std::string& username, const std::string& password) override {
        if (username.empty() || password.empty()) throw std::invalid_argument("Username and password cannot be empty");
        if (password.length() < 6) throw std::runtime_error("Password too short");
        std::cout << "Regular user logged in: " << username << std::endl;
    }
};

// 13.
class ScalableShape {
public:
    virtual void scale(double factor) = 0;
    virtual ~ScalableShape() {}
};

class ScalableCircle : public ScalableShape {
    double radius;
public:
    ScalableCircle(double r) : radius(r) {
        if (r <= 0) throw std::invalid_argument("Radius must be positive");
    }
    void scale(double factor) override {
        if (factor <= 0) throw std::invalid_argument("Scale factor must be positive");
        radius *= factor;
        std::cout << "Circle scaled to radius " << radius << std::endl;
    }
};

class ScalableSquare : public ScalableShape {
    double side;
public:
    ScalableSquare(double s) : side(s) {
        if (s <= 0) throw std::invalid_argument("Side must be positive");
    }
    void scale(double factor) override {
        if (factor <= 0) throw std::invalid_argument("Scale factor must be positive");
        side *= factor;
        std::cout << "Square scaled to side " << side << std::endl;
    }
};

// 14.
class Library {
public:
    virtual void borrowBook(const std::string& title) = 0;
    virtual ~Library() {}
};

class FictionLibrary : public Library {
    std::vector<std::string> availableBooks = { "Harry Potter", "Lord of the Rings" };
public:
    void borrowBook(const std::string& title) override {
        if (std::find(availableBooks.begin(), availableBooks.end(), title) == availableBooks.end())
            throw std::runtime_error("Fiction book not available: " + title);
        std::cout << "Borrowed fiction book: " << title << std::endl;
    }
};

class NonFictionLibrary : public Library {
    std::vector<std::string> availableBooks = { "Sapiens", "Atomic Habits" };
public:
    void borrowBook(const std::string& title) override {
        if (std::find(availableBooks.begin(), availableBooks.end(), title) == availableBooks.end())
            throw std::runtime_error("Non-fiction book not available: " + title);
        std::cout << "Borrowed non-fiction book: " << title << std::endl;
    }
};

// 15.
class Order {
public:
    virtual void process() = 0;
    virtual ~Order() {}
};

class OnlineOrder : public Order {
    std::string items;
public:
    OnlineOrder(const std::string& i) : items(i) {
        if (i.empty()) throw std::invalid_argument("Order items cannot be empty");
    }
    void process() override {
        std::cout << "Processing online order: " << items << std::endl;
    }
};

class InStoreOrder : public Order {
    std::string items;
public:
    InStoreOrder(const std::string& i) : items(i) {
        if (i.empty()) throw std::invalid_argument("Order items cannot be empty");
    }
    void process() override {
        std::cout << "Processing in-store order: " << items << std::endl;
    }
};

// 16.
class RotatableShape {
public:
    virtual void rotate(double angle) = 0;
    virtual ~RotatableShape() {}
};

class RotatableTriangle : public RotatableShape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle > 360) throw std::invalid_argument("Angle must be between 0 and 360 degrees");
        std::cout << "Triangle rotated by " << angle << " degrees" << std::endl;
    }
};

class RotatableRectangle : public RotatableShape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle > 360) throw std::invalid_argument("Angle must be between 0 and 360 degrees");
        std::cout << "Rectangle rotated by " << angle << " degrees" << std::endl;
    }
};

// 17.
class Payment {
protected:
    double amount;
public:
    Payment(double a) : amount(a) {
        if (a <= 0) throw std::invalid_argument("Amount must be positive");
    }
    virtual void processPayment() = 0;
    virtual ~Payment() {}
};

class CreditCardPayment : public Payment {
    std::string cardNumber;
public:
    CreditCardPayment(double a, const std::string& cn) : Payment(a), cardNumber(cn) {
        if (cn.length() != 16) throw std::invalid_argument("Invalid card number");
    }
    void processPayment() override {
        std::cout << "Processing credit card payment of $" << amount << std::endl;
    }
};

class PayPalPayment : public Payment {
    std::string email;
public:
    PayPalPayment(double a, const std::string& e) : Payment(a), email(e) {
        if (e.find('@') == std::string::npos) throw std::invalid_argument("Invalid email");
    }
    void processPayment() override {
        std::cout << "Processing PayPal payment of $" << amount << " to " << email << std::endl;
    }
};

// 18.
class ExceptionHandler {
public:
    virtual void handle(const std::exception& e) = 0;
    virtual ~ExceptionHandler() {}
};

class FileExceptionHandler : public ExceptionHandler {
public:
    void handle(const std::exception& e) override {
        std::cerr << "File Exception: " << e.what() << std::endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const std::exception& e) override {
        std::cerr << "Network Exception: " << e.what() << std::endl;
    }
};

// 19.
class Course {
protected:
    int capacity;
    int enrolled;
public:
    Course(int c) : capacity(c), enrolled(0) {}
    virtual void enroll() {
        if (enrolled >= capacity) throw std::runtime_error("Course is full");
        enrolled++;
        std::cout << "Enrolled in course. Current students: " << enrolled << std::endl;
    }
    virtual ~Course() {}
};

class OnlineCourse : public Course {
public:
    OnlineCourse(int c) : Course(c) {}
    void enroll() override {
        if (enrolled >= capacity) throw std::runtime_error("Online course is full");
        enrolled++;
        std::cout << "Enrolled in online course. Current students: " << enrolled << std::endl;
    }
};

class OfflineCourse : public Course {
public:
    OfflineCourse(int c) : Course(c) {}
    void enroll() override {
        if (enrolled >= capacity) throw std::runtime_error("Offline course is full");
        enrolled++;
        std::cout << "Enrolled in offline course. Current students: " << enrolled << std::endl;
    }
};

// 20.
class ShoppingCart {
public:
    virtual void checkout() = 0;
    virtual ~ShoppingCart() {}
};

class RegularCart : public ShoppingCart {
    std::vector<std::string> items;
public:
    void addItem(const std::string& item) {
        items.push_back(item);
    }
    void checkout() override {
        if (items.empty()) throw std::runtime_error("Cannot checkout empty cart");
        std::cout << "Checking out regular cart with " << items.size() << " items" << std::endl;
    }
};

class DiscountedCart : public ShoppingCart {
    std::vector<std::string> items;
    double discount;
public:
    DiscountedCart(double d) : discount(d) {
        if (d < 0 || d > 1) throw std::invalid_argument("Discount must be between 0 and 1");
    }
    void addItem(const std::string& item) {
        items.push_back(item);
    }
    void checkout() override {
        if (items.empty()) throw std::runtime_error("Cannot checkout empty cart");
        std::cout << "Checking out discounted cart with " << items.size()
            << " items and " << (discount * 100) << "% discount" << std::endl;
    }
};

int main() {
    try {
        Circle c(10);
        std::cout << "Circle area: " << c.area() << std::endl;

        Dog d("Шариг");
        d.speak();

        SavingsAccount sa(100);
        sa.withdraw(250);

        TextFileHandler tfh;
        tfh.open("example.txt");

        Triangle t(3, 4, 5);
        t.draw();

        Student s("Алиса", 20);
        s.display();

        Division div;
        std::cout << "10 / 2 = " << div.calculate(10, 2) << std::endl;

        Tennis tennis(2);
        tennis.start();

        PDFDocument pdf;
        pdf.save("document.pdf");

        IntMatrix im(3, 3);
        std::cout << "Matrix element: " << im.getElement(0, 0) << std::endl;

        Car car(30);
        std::cout << "Car MPG: " << car.fuelEfficiency() << std::endl;

        RegularUser ru;
        ru.login("user1", "password123");

        ScalableCircle sc(10);
        sc.scale(1.5);

        FictionLibrary fl;
        fl.borrowBook("Harry Potter");

        OnlineOrder oo("Laptop, Mouse");
        oo.process();

        RotatableRectangle rr;
        rr.rotate(45);

        PayPalPayment pp(100, "user@example.com");
        pp.processPayment();

        FileExceptionHandler feh;
        try {
            throw std::runtime_error("File not found");
        }
        catch (const std::exception& e) {
            feh.handle(e);
        }

        OnlineCourse oc(50);
        oc.enroll();

        RegularCart rc;
        rc.addItem("Book");
        rc.checkout();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}