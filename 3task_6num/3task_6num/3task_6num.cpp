#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    size_t capacity;
    size_t size;
    size_t front;
    size_t rear;

    void resize() {
        size_t new_capacity = capacity * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
        front = 0;
        rear = size;
    }

public:
    Queue() : capacity(10), size(0), front(0), rear(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (size == capacity) {
            resize();
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        ++size;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Ochered' pusta");
        }
        T value = data[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Ochered' pusta" << std::endl;
            return;
        }
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[(front + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};

void intQueueOperations() {
    Queue<int> intQueue;
    while (true) {
        std::cout << "Vyberite operatsiyu dlya ocheredi int (1: dobavit', 2: udalit', 3: vyvesti, 4: vyiti): ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Vvedite tseloe chislo dlya dobavleniya v ochered': ";
            int value;
            std::cin >> value;
            intQueue.enqueue(value);
        }
        else if (choice == 2) {
            try {
                int value = intQueue.dequeue();
                std::cout << "Udaleno iz ocheredi: " << value << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 3) {
            intQueue.printQueue();
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Neverny vybor, poprobuite eshe raz." << std::endl;
        }
    }
}

void stringQueueOperations() {
    Queue<std::string> stringQueue;
    while (true) {
        std::cout << "Vyberite operatsiyu dlya ocheredi string (1: dobavit', 2: udalit', 3: vyvesti, 4: vyiti): ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Vvedite stroku dlya dobavleniya v ochered': ";
            std::string value;
            std::cin >> value;
            stringQueue.enqueue(value);
        }
        else if (choice == 2) {
            try {
                std::string value = stringQueue.dequeue();
                std::cout << "Udaleno iz ocheredi: " << value << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 3) {
            stringQueue.printQueue();
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Neverny vybor, poprobuite eshe raz." << std::endl;
        }
    }
}

int main() {
    while (true) {
        std::cout << "Vyberite tip ocheredi (1: int, 2: string, 3: vyiti): ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            intQueueOperations();
        }
        else if (choice == 2) {
            stringQueueOperations();
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Neverny vybor, poprobuite eshe raz." << std::endl;
        }
    }
    return 0;
}
