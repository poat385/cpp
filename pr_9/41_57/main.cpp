#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

// ============================================
// ЗАДАНИЕ 41: Абстрактный класс Shape с area()
// ============================================
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    double area() const override {
        return width * height;
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
        if (a <= 0 || b <= 0 || c <= 0) throw invalid_argument("Стороны должны быть положительными");
        if (a + b <= c || a + c <= b || b + c <= a) throw invalid_argument("Неверные стороны треугольника");
    }
    double area() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

// ============================================
// ЗАДАНИЕ 42: Класс Employee с calculateSalary()
// ============================================
class Employee {
public:
    virtual double calculateSalary(double hours) const = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
public:
    double calculateSalary(double hours) const override {
        if (hours < 0) throw invalid_argument("Часы работы не могут быть отрицательными");
        return 50000 + max(0.0, hours - 40) * 500;
    }
};

class PartTimeEmployee : public Employee {
public:
    double calculateSalary(double hours) const override {
        if (hours < 0) throw invalid_argument("Часы работы не могут быть отрицательными");
        return hours * 1000;
    }
};

// ============================================
// ЗАДАНИЕ 43: Класс DataReader с readData()
// ============================================
class DataReader {
public:
    virtual void readData(const string& filename) = 0;
    virtual ~DataReader() {}
};

class CSVReader : public DataReader {
public:
    void readData(const string& filename) override {
        if (filename.empty()) throw runtime_error("Имя файла не может быть пустым");
        cout << "Чтение CSV файла: " << filename << endl;
    }
};

class XMLReader : public DataReader {
public:
    void readData(const string& filename) override {
        if (filename.find(".xml") == string::npos) throw runtime_error("Неверный формат XML файла");
        cout << "Чтение XML файла: " << filename << endl;
    }
};

// ============================================
// ЗАДАНИЕ 44: Класс Shape с scale()
// ============================================
class ScalableShape {
public:
    virtual void scale(double factor) = 0;
    virtual ~ScalableShape() {}
};

class ScalableCircle : public ScalableShape {
    double radius;
public:
    ScalableCircle(double r) : radius(r) {}
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Масштаб должен быть положительным");
        radius *= factor;
        cout << "Круг масштабирован. Новый радиус: " << radius << endl;
    }
};

// ============================================
// ЗАДАНИЕ 45: Класс BankAccount с transfer()
// ============================================
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double initial) : balance(initial) {}
    virtual void transfer(double amount) = 0;
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double initial) : BankAccount(initial) {}
    void transfer(double amount) override {
        if (amount > balance) throw runtime_error("Недостаточно средств на сберегательном счете");
        balance -= amount;
        cout << "Переведено " << amount << ". Остаток: " << balance << endl;
    }
};

// ============================================
// ЗАДАНИЕ 46: NetworkRequest с send()
// ============================================
class NetworkRequest {
    public:
        virtual void send(const string& url) = 0;
        virtual ~NetworkRequest() {}
    };
    
    class HttpRequest : public NetworkRequest {
    public:
        void send(const string& url) override {
            if (url.empty()) throw runtime_error("URL не может быть пустым");
            if (url.find("http://") != 0 && url.find("https://") != 0)
                throw runtime_error("Неверный формат HTTP URL");
            cout << "Отправка HTTP запроса: " << url << endl;
        }
    };
    
    class FtpRequest : public NetworkRequest {
    public:
        void send(const string& url) override {
            if (url.empty()) throw runtime_error("URL не может быть пустым");
            if (url.find("ftp://") != 0)
                throw runtime_error("Неверный формат FTP URL");
            cout << "Отправка FTP запроса: " << url << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 47: Shape с getBoundingBox()
    // ============================================
    class BoundingShape {
    public:
        virtual void getBoundingBox() const = 0;
        virtual ~BoundingShape() {}
    };
    
    class BoundingCircle : public BoundingShape {
        double radius;
    public:
        BoundingCircle(double r) : radius(r) {
            if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
        }
        void getBoundingBox() const override {
            cout << "Границы круга: квадрат со стороной " << 2*radius << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 48: Иерархия исключений
    // ============================================
    class MyException : public exception {
    protected:
        string message;
    public:
        virtual const char* what() const noexcept override = 0;
        virtual ~MyException() {}
    };
    
    class FileNotFoundException : public MyException {
    public:
        FileNotFoundException() { message = "Файл не найден"; }
        const char* what() const noexcept override { return message.c_str(); }
    };
    
    class InvalidInputException : public MyException {
    public:
        InvalidInputException() { message = "Неверные входные данные"; }
        const char* what() const noexcept override { return message.c_str(); }
    };
    
    // ============================================
    // ЗАДАНИЕ 49: Task с execute()
    // ============================================
    class Task {
    public:
        virtual void execute() = 0;
        virtual ~Task() {}
    };
    
    class PrintTask : public Task {
        string text;
    public:
        PrintTask(const string& t) : text(t) {}
        void execute() override {
            if (text.empty()) throw runtime_error("Текст для печати не может быть пустым");
            cout << "Печать: " << text << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 50: Shape с rotate()
    // ============================================
    class RotatableShape {
    public:
        virtual void rotate(double angle) = 0;
        virtual ~RotatableShape() {}
    };
    
    class RotatableSquare : public RotatableShape {
    public:
        void rotate(double angle) override {
            if (angle < 0 || angle > 360) throw invalid_argument("Угол должен быть от 0 до 360 градусов");
            cout << "Квадрат повернут на " << angle << " градусов" << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 51: User с login()
    // ============================================
    class User {
    public:
        virtual void login(const string& password) = 0;
        virtual ~User() {}
    };
    
    class AdminUser : public User {
        const string adminPass = "admin123";
    public:
        void login(const string& password) override {
            if (password != adminPass) throw runtime_error("Неверный пароль администратора");
            cout << "Администратор вошел в систему" << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 52: Payment с process()
    // ============================================
    class Payment {
    protected:
        double balance;
    public:
        Payment(double b) : balance(b) {}
        virtual void process(double amount) = 0;
        virtual ~Payment() {}
    };
    
    class CreditCardPayment : public Payment {
    public:
        CreditCardPayment(double b) : Payment(b) {}
        void process(double amount) override {
            if (amount > balance) throw runtime_error("Недостаточно средств на карте");
            balance -= amount;
            cout << "Оплата картой: " << amount << ". Остаток: " << balance << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 53: Shape с getArea()
    // ============================================
    class AreaShape {
    public:
        virtual double getArea() const = 0;
        virtual ~AreaShape() {}
    };
    
    class AreaCircle : public AreaShape {
        double radius;
    public:
        AreaCircle(double r) : radius(r) {
            if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
        }
        double getArea() const override {
            return 3.14159 * radius * radius;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 54: FileHandler с open()
    // ============================================
    class FileHandler {
    public:
        virtual void open(const string& filename) = 0;
        virtual ~FileHandler() {}
    };
    
    class TextFileHandler : public FileHandler {
    public:
        void open(const string& filename) override {
            if (filename.empty()) throw runtime_error("Имя файла не может быть пустым");
            if (filename.find(".txt") == string::npos)
                throw runtime_error("Неверный формат текстового файла");
            cout << "Открытие текстового файла: " << filename << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 55: Database с query()
    // ============================================
    class Database {
    public:
        virtual void query(const string& sql) = 0;
        virtual ~Database() {}
    };
    
    class MySQLDatabase : public Database {
    public:
        void query(const string& sql) override {
            if (sql.empty()) throw runtime_error("SQL запрос не может быть пустым");
            cout << "Выполнение MySQL запроса: " << sql << endl;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 56: Shape с getVertices()
    // ============================================
    class VertexShape {
    public:
        virtual vector<pair<double, double>> getVertices() const = 0;
        virtual ~VertexShape() {}
    };
    
    class TriangleShape : public VertexShape {
        vector<pair<double, double>> vertices;
    public:
        TriangleShape(pair<double, double> v1, pair<double, double> v2, pair<double, double> v3) {
            vertices = {v1, v2, v3};
        }
        vector<pair<double, double>> getVertices() const override {
            if (vertices.size() != 3) throw runtime_error("У треугольника должно быть 3 вершины");
            return vertices;
        }
    };
    
    // ============================================
    // ЗАДАНИЕ 57: Logger с log()
    // ============================================
    class Logger {
    public:
        virtual void log(const string& message) = 0;
        virtual ~Logger() {}
    };
    
    class FileLogger : public Logger {
    public:
        void log(const string& message) override {
            if (message.empty()) throw runtime_error("Сообщение лога не может быть пустым");
            cout << "Запись в файл лога: " << message << endl;
        }
    };
    

// ============================================
// ОСНОВНАЯ ФУНКЦИЯ
// ============================================
int main() {
    try {
        // Задание 41
        cout << "\n=== Задание 41 ===" << endl;
        Circle c(5);
        cout << "Площадь круга: " << c.area() << endl;

        // Задание 42
        cout << "\n=== Задание 42 ===" << endl;
        FullTimeEmployee ft;
        cout << "Зарплата (45 часов): " << ft.calculateSalary(45) << endl;

        // Задание 43
        cout << "\n=== Задание 43 ===" << endl;
        CSVReader csv;
        csv.readData("data.csv");

        // Задание 44
        cout << "\n=== Задание 44 ===" << endl;
        ScalableCircle sc(10);
        sc.scale(1.5);

        // Задание 45
        cout << "\n=== Задание 45 ===" << endl;
        SavingsAccount sa(1000);
        sa.transfer(500);

 // Задание 46
        cout << "\n=== Задание 46 ===" << endl;
        HttpRequest http;
        http.send("https://example.com");

        // Задание 47
        cout << "\n=== Задание 47 ===" << endl;
        BoundingCircle bc(5);
        bc.getBoundingBox();

        // Задание 48
        cout << "\n=== Задание 48 ===" << endl;
        try {
            throw FileNotFoundException();
        } catch (const MyException& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }

        // Задание 49
        cout << "\n=== Задание 49 ===" << endl;
        PrintTask pt("Hello World");
        pt.execute();

        // Задание 50
        cout << "\n=== Задание 50 ===" << endl;
        RotatableSquare rs;
        rs.rotate(45);

        // Задание 51
        cout << "\n=== Задание 51 ===" << endl;
        AdminUser admin;
        // admin.login("wrong"); // выбросит исключение
        admin.login("admin123");

        // Задание 52
        cout << "\n=== Задание 52 ===" << endl;
        CreditCardPayment cc(1000);
        cc.process(500);

        // Задание 53
        cout << "\n=== Задание 53 ===" << endl;
        AreaCircle ac(3);
        cout << "Площадь круга: " << ac.getArea() << endl;

        // Задание 54
        cout << "\n=== Задание 54 ===" << endl;
        TextFileHandler tfh;
        tfh.open("document.txt");

        // Задание 55
        cout << "\n=== Задание 55 ===" << endl;
        MySQLDatabase mysql;
        mysql.query("SELECT * FROM users");

        // Задание 56
        cout << "\n=== Задание 56 ===" << endl;
        TriangleShape triangle({0,0}, {1,0}, {0,1});
        auto vertices = triangle.getVertices();
        cout << "Вершины треугольника: ";
        for (const auto& v : vertices) {
            cout << "(" << v.first << "," << v.second << ") ";
        }
        cout << endl;

        // Задание 57
        cout << "\n=== Задание 57 ===" << endl;
        FileLogger flogger;
        flogger.log("Система запущена");


    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}