#include <iostream>
#include <stdexcept> 

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* frontPtr;
    Node* backPtr; 
    size_t size;   

public:
    Queue() : frontPtr(nullptr), backPtr(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontPtr = backPtr = newNode;
        } else {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Очередь пуста");
        }
        
        Node* temp = frontPtr;
        T value = temp->data;
        frontPtr = frontPtr->next;
        
        if (frontPtr == nullptr) {
            backPtr = nullptr;
        }
        
        delete temp;
        size--;
        return value;
    }

    T& front() const {
        if (isEmpty()) {
            throw std::runtime_error("Очередь пуста");
        }
        return frontPtr->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
};

int main() {
    Queue<int> intQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    std::cout << "Размер очереди: " << intQueue.getSize() << "\n";
    std::cout << "Первый элемент: " << intQueue.front() << "\n";

    std::cout << "Извлечено: " << intQueue.dequeue() << "\n";
    std::cout << "Извлечено: " << intQueue.dequeue() << "\n";

    intQueue.enqueue(40);
    intQueue.enqueue(50);

    while (!intQueue.isEmpty()) {
        std::cout << "Извлечено: " << intQueue.dequeue() << "\n";
    }

    Queue<std::string> stringQueue;
    stringQueue.enqueue("Привет");
    stringQueue.enqueue("Мир");
    
    while (!stringQueue.isEmpty()) {
        std::cout << stringQueue.dequeue() << " ";
    }

    return 0;
}