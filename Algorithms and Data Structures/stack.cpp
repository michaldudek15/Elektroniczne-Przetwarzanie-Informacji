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
};

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top == MAX - 1);
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "stack is empty" << endl;
        return 0;
    }
    else {
        return tab[top];
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "stack is empty" << endl;
        return 0;
    }
    else {
        return tab[top--];
    }
}

bool Stack::push (int newData) {
    if (isFull()) {
        cout << "stack is full" << endl;
        return false;
    }
    else {
        tab[++top] = newData;
        cout << newData << " pushed into stack" << endl;
        return true;
    }
}

int main() {

    Stack stos;
    stos.push(5);
    stos.push(19);
    cout << stos.peek() << endl;
    stos.pop();
    cout << stos.peek() << endl;
    stos.pop();
    cout << stos.peek() << endl;




    return 0;
}