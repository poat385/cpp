#include <iostream>
#include <stdexcept>

class Task {
protected:
    bool initialized_{false}; 

public:
    virtual ~Task() = default;

    virtual void execute() {
        if (!initialized_) {
            throw std::logic_error("Задача не инициализирована.");
        }
        doExecute(); 
    }

    virtual void initialize() {
        initialized_ = true;
    }

protected:
    virtual void doExecute() = 0;
};

class PrintTask : public Task {
protected:
    std::string text_; 

public:
    PrintTask(const std::string& text) : text_(text) {}

    void initialize() override {
        Task::initialize(); 
    }

protected:
    void doExecute() override {
        std::cout << "Выводим текст: " << text_ << std::endl;
    }
};

class EmailTask : public Task {
protected:
    std::string recipient_; 
    std::string subject_;   
    std::string body_;      

public:
    EmailTask(const std::string& recipient, const std::string& subject, const std::string& body)
        : recipient_(recipient), subject_(subject), body_(body) {}

    void initialize() override {
        Task::initialize();
    }

protected:
    void doExecute() override {
        std::cout << "Отправляем письмо на адрес " << recipient_
                  << ", тема \"" << subject_ << "\": " << body_ << std::endl;
    }
};

int main() {
    try {
        PrintTask task("Привет, мир!");
        task.initialize(); 
        task.execute();    

        EmailTask emailTask("example@example.com", "Тестовое письмо", "Здравствуйте!");
        emailTask.initialize(); 
        emailTask.execute();    
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}