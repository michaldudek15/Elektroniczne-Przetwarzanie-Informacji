#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    private: 
        int top;
        int currentSize;

    public:
        int tab[MAX];

        bool isEmpty();
        bool isFull();
        bool push(int x);
        int pop();
        int peek();

        Stack() {
            top = -1;
        };
        ~Stack() {
            delete []tab;
        };
};

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top == MAX - 1);
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "stack is empty";
        return 0;
    }
    else {
        return tab[top];
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "stack is empty";
        return 0;
    }
    else {
        return tab[top--];
    }
}

bool Stack::push (int newData) {
    if (isFull()) {
        cout << "stack is full";
        return false;
    }
    else {
        tab[++top] = newData;
        cout << newData << " pushed into stack";
        return true;
    }
}

int main() {

    Stack stos;
    stos.push(5);
    stos.push(19);
    stos.peek();




    return 0;
}