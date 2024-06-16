#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Queue {
private:
    T* elements;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int capacity) : capacity(capacity), frontIndex(0), rearIndex(-1), count(0) {
        elements = new T[capacity];
    }

    ~Queue() {
        delete[] elements;
    }

    void enqueue(T element) {
        if (count == capacity) {
            resize();
        }
        rearIndex = (rearIndex + 1) % capacity;
        elements[rearIndex] = element;
        count++;
        }
    

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }else{
        T frontElement = elements[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return frontElement;
        }
    }

    T first() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot retrieve first element." << endl;
        }else return elements[frontIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    int queueSize() {
        return count;
    }

    void clear() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void print() {
        int i = frontIndex;
        int elementsPrinted = 0;
        while (elementsPrinted < count) {
            cout << elements[i] << " ";
            i = (i + 1) % capacity;
            elementsPrinted++;
        }
        cout << endl;
    }
    
    void resize() {
        int newCapacity = capacity * 2; // Double the capacity
        T* newElements = new T[newCapacity];

        // Copy elements to the new array
        int j = 0;
        for (int i = frontIndex; i != (rearIndex + 1) % capacity; i = (i + 1) % capacity) {
            newElements[j++] = elements[i];
        }

        delete[] elements;
        elements = newElements;
        frontIndex = 0;
        rearIndex = count - 1;
        capacity = newCapacity;
    }
};

int main() {
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << "Queue elements: ";
    q.print();

    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "First element: " << q.first() << endl;

    cout << "Queue size: " << q.queueSize() << endl;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Clearing queue..." << endl;
    q.clear();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Queue is destroyed. " << endl;
    q.~Queue();

    return 0;
}