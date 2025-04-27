#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

void shapeDemo() {
    vector<Shape*> shapes = {
        new Circle(5),
        new Rectangle(4, 6)
    };
    
    for (auto shape : shapes) {
        cout << "Площадь: " << shape->area() << endl;
        delete shape;
    }
};
//2
class Animal {
    public:
        virtual void sound() const = 0;
        virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() const override { cout << "Гав!" << endl; }
};

class Cat : public Animal {
public:
    void sound() const override { cout << "Мяу!" << endl; }
};

void animalDemo() {
    vector<Animal*> animals = {
        new Dog(),
        new Cat()
    };
    
    for (auto animal : animals) {
        animal->sound();
        delete animal;
    }
};
//3
class Employee {
    public:
        virtual double calculateSalary() const = 0;
        virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double monthlySalary;
public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() const override { return monthlySalary; }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTimeEmployee(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
};

void employeeDemo() {
    vector<Employee*> employees = {
        new FullTimeEmployee(5000),
        new PartTimeEmployee(20, 80)
    };
    
    for (auto emp : employees) {
        cout << "Зарплата: " << emp->calculateSalary() << endl;
        delete emp;
    }
};
//4
class Vehicle {
    public:
        virtual void move() const = 0;
        virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void move() const override { cout << "Машина едет" << endl; }
};

class Bike : public Vehicle {
public:
    void move() const override { cout << "Велосипед крутит педали" << endl; }
};

void vehicleDemo() {
    vector<Vehicle*> vehicles = {
        new Car(),
        new Bike()
    };
    
    for (auto v : vehicles) {
        v->move();
        delete v;
    }
};
//5
class Account {
    protected:
        double balance;
    public:
        Account(double b) : balance(b) {}
        virtual void withdraw(double amount) = 0;
        virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        if (balance - amount >= 0) balance -= amount;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        balance -= amount;
    }
};

void accountDemo() {
    vector<Account*> accounts = {
        new SavingsAccount(1000),
        new CheckingAccount(1000)
    };
    
    for (auto acc : accounts) {
        acc->withdraw(200);
        delete acc;
    }
};
//6
class Media {
    public:
        virtual void play() const = 0;
        virtual ~Media() {}
};

class Audio : public Media {
public:
    void play() const override { cout << "Воспроизводится аудио..." << endl; }
};

class Video : public Media {
public:
    void play() const override { cout << "Воспроизводится видео..." << endl; }
};

void mediaDemo() {
    vector<Media*> media = {
        new Audio(),
        new Video()
    };
    
    for (auto m : media) {
        m->play();
        delete m;
    }
};
//7
class Person {
    public:
        virtual void introduce() const = 0;
        virtual ~Person() {}
};

class Student : public Person {
public:
    void introduce() const override { cout << "Я студент" << endl; }
};

class Teacher : public Person {
public:
    void introduce() const override { cout << "Я учитель" << endl; }
};

void personDemo() {
    vector<Person*> people = {
        new Student(),
        new Teacher()
    };
    
    for (auto p : people) {
        p->introduce();
        delete p;
    }
};
//8
class Book {
    public:
        virtual void getInfo() const = 0;
        virtual ~Book() {}
};

class EBook : public Book {
public:
    void getInfo() const override { cout << "Электронная книга" << endl; }
};

class PrintedBook : public Book {
public:
    void getInfo() const override { cout << "Печатная книга" << endl; }
};

void bookDemo() {
    vector<Book*> books = {
        new EBook(),
        new PrintedBook()
    };
    
    for (auto b : books) {
        b->getInfo();
        delete b;
    }
};
//9
class Appliance {
    public:
        virtual void turnOn() const = 0;
        virtual ~Appliance() {}
};

class WashingMachine : public Appliance {
public:
    void turnOn() const override { cout << "Стиральная машина запущена" << endl; }
};

class Refrigerator : public Appliance {
public:
    void turnOn() const override { cout << "Холодильник охлаждает" << endl; }
};

void applianceDemo() {
    vector<Appliance*> appliances = {
        new WashingMachine(),
        new Refrigerator()
    };
    
    for (auto a : appliances) {
        a->turnOn();
        delete a;
    }
};
//10
class Game {
    public:
        virtual void play() const = 0;
        virtual ~Game() {}
};

class BoardGame : public Game {
public:
    void play() const override { cout << "Играем в настольную игру" << endl; }
};

class VideoGame : public Game {
public:
    void play() const override { cout << "Играем в видеоигру" << endl; }
};

void gameDemo() {
    vector<Game*> games = {
        new BoardGame(),
        new VideoGame()
    };
    
    for (auto g : games) {
        g->play();
        delete g;
    }
};

int main() {
    shapeDemo();
    animalDemo();
    employeeDemo();
    vehicleDemo();
    accountDemo();
    mediaDemo();
    personDemo();
    bookDemo();
    applianceDemo();
    gameDemo();
    
    return 0;
}