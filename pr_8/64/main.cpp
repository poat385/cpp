#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
class TaskManager {
    public:
        virtual void runTask(const std::string& task) = 0;
        virtual ~TaskManager() {}
    };
    
    class ScheduledTask : public TaskManager {
    public:
        void runTask(const std::string& task) override {
            if (task.empty()) throw std::runtime_error("Task cannot be empty");
            std::cout << "Running scheduled task: " << task << std::endl;
        }
    };
    
    class ImmediateTask : public TaskManager {
    public:
        void runTask(const std::string& task) override {
            if (task.empty()) throw std::runtime_error("Task cannot be empty");
            std::cout << "Running immediate task: " << task << std::endl;
        }
    };


    int main() {
        ImmediateTask task;
        
        try {
            task.runTask(""); // Попытка запустить пустую задачу
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        
        return 0;
    }