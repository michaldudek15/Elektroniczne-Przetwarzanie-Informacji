#include <iostream>
using namespace std;

#define sizeLimit 1000

class Stack {
    private: 
        int top; //index of element at the top of stack

    public:
        int tab[sizeLimit]; //array with data kept in stack

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
    return (top == sizeLimit - 1);
}

int Stack::peek() {
    /*
    check element at the top of stack
    */
    if (isEmpty()) {
        cout << "stack is empty" << endl;
        return 0;
    }
    else {
        return tab[top];
    }
}

int Stack::pop() {
    /*
    delete and return element at the top of stack
    */
    if (isEmpty()) {
        cout << "stack is empty" << endl;
        return 0;
    }
    else {
        return tab[top--];
    }
}

bool Stack::push (int newData) {
    /* 
    add new element above current top element
    */
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
    stos.push(25);
    cout << stos.peek() << endl;
    stos.pop();
    cout << stos.peek() << endl;
    stos.pop();

    return 0;
}