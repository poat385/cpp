#include <iostream>
#include <vector>   

template <typename T>
class Stack {
private:
    std::vector<T> elements_;

public:
    // Добавление элемента в вершину стека
    void push(const T& value) {
        elements_.push_back(value);
    }

    // Удаление последнего добавленного элемента
    void pop() {
        if (!empty()) {
            elements_.pop_back();
        }
    }

    // Получаем верхний элемент стека
    const T& top() const {
        if (!empty()) {
            return elements_.back();
        }
        throw std::out_of_range("Стэк пуст");
    }

    // Проверяем, пустой ли стек
    bool empty() const {
        return elements_.empty();
    }

    // Возвращаем количество элементов в стеке
    size_t size() const {
        return elements_.size();
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.empty()) {
        std::cout << "Верхний элемент: " << stack.top() << '\n';
        stack.pop();
    }

    return 0;
}