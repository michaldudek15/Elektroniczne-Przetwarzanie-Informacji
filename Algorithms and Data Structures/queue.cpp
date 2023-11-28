#include <iostream>
using namespace std;

#define sizeLimit 10

class Queue {
    private:
        int currentSize;
        int first;

    public:
        int data[sizeLimit];
        int front();
        void enqueue(int newItem);
        void dequeue();
        bool isEmpty();
        bool isFull();

        Queue() {
            first = 0;
            currentSize = 0;
        }
};

int Queue::front() {
    if (isEmpty()) return 0;
    else return data[first];
}

void Queue::enqueue(int newItem) {
    if (isFull()) {
        cout << "queue is full" << endl;
        return;
    }
    int last = (first + currentSize) % sizeLimit;
    data[last] = newItem;
    currentSize++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "queue is empty" << endl;
        return;
    }
    first = (first + 1) % sizeLimit;
    currentSize--;
}

bool Queue::isEmpty() {
    return !currentSize;
}

bool Queue::isFull() {
    return (currentSize == sizeLimit);
}

int main() {

    Queue kolejka;
    kolejka.enqueue(5);
    cout << kolejka.front() << endl;
    kolejka.enqueue(10);
    cout << kolejka.front() << endl;
    kolejka.dequeue();
    cout << kolejka.front() << endl;
    kolejka.dequeue();
    cout << kolejka.front() << endl;
    kolejka.dequeue();
    cout << kolejka.front() << endl;

    return 0;
}