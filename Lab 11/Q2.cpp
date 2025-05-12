#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "QueueOverflowException - what(): std::exception";
    }
};

class QueueUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "QueueUnderflowException - what(): std::exception";
    }
};

template<typename T, int CAPACITY>
class Queue {
    T arr[CAPACITY];
    int front, rear, size;
public:
    Queue() : front(0), rear(-1), size(0) {}
    void enqueue(T val) {
        if (size == CAPACITY)
            throw QueueOverflowException();
        rear = (rear + 1) % CAPACITY;
        arr[rear] = val;
        ++size;
    }
    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();
        T val = arr[front];
        front = (front + 1) % CAPACITY;
        --size;
        return val;
    }
};

int main() {
    Queue<int, 2> q;
    cout << "Attempting to enqueue to a full queue..." << endl;
    try {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
    }
    catch (const exception& e) {
        cout << "Caught " << e.what() << endl;
    }
    cout << "Attempting to dequeue from an empty queue..." << endl;
    try {
        q.dequeue();
        q.dequeue();
        q.dequeue();
    }
    catch (const exception& e) {
        cout << "Caught " << e.what() << endl;
    }
    return 0;
}
