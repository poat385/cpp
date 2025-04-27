#include <iostream>
#include <stdexcept> 

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head; 
    Node* tail; 
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        
        Node* temp = head;
        head = head->next;
        
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; 
        }
        
        delete temp;
        size--;
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        
        Node* temp = tail;
        tail = tail->prev;
        
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; 
        }
        
        delete temp;
        size--;
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    List(const List&) = delete;
    List& operator=(const List&) = delete;
};

int main() {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.push_front(1);

    std::cout << "List after additions: ";
    list.print(); 

    list.pop_front();
    list.pop_back();

    std::cout << "List after deletions: ";
    list.print(); 


    std::cout << "Front: " << list.front() << "\n";
    std::cout << "Back: " << list.back() << "\n";  

    
    list.clear();
    std::cout << "List after clear is empty: " 
              << std::boolalpha << list.empty() << "\n"; 

    return 0;
}