#include <iostream>
#include <iomanip>
using namespace std;

const int MAXINT = 2147483647;
const int N = 10;
bool visited[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int vs, ve;

// int matrix[N][N] = {
//  	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//    	{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
//    	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
//    	{ 0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
//    	{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
//    	{ 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
//    	{ 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
//    	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
//    	{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
//    	{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
// };

int matrix[N][N] = {
 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
   	{ 0, 1, 0, 1, 0, 0, 1, 1, 0, 0},
   	{ 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
   	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
   	{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
   	{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
   	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
   	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
   	{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

struct slistEl {
    slistEl* next;
    int data;
};

class Queue {
    private:
    slistEl* head;
    slistEl* tail;

    public:
    Queue();
    ~Queue();
    bool empty();
    int front();
    void push(int v);
    void pop();
};

class Stack {
    private:
        slistEl* S;

    public:
        Stack();
        ~Stack();
        bool empty();
        int top();
        void push(int v);
        void pop();
};

Stack S;
int P[N] ={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

Queue::Queue() {
    head = tail = NULL;
}

Queue::~Queue() {
    while (head)
        pop();
}

bool Queue::empty() {
    return !head;
}

int Queue::front() {
    if (head)
        return head->data;
    else    
        return MAXINT;
}

void Queue::push(int v) {
    slistEl* p = new slistEl;
    p->next = NULL;
    p->data = v;
    if (tail)
        tail->next = p;
    else    
        head = p;
    tail = p;
}

void Queue::pop() {
    if (head) {
        slistEl* p = head;
        head = head->next;
        if (!head)
            tail = NULL;
        delete p;
    }
}

Stack::Stack() {
    S = NULL;
}

Stack::~Stack() {
    while (S)
        pop();
}

bool Stack::empty() {
    return !S;
}

int Stack::top(){
    return S->data;
}

void Stack::push(int v) {
    slistEl* e = new slistEl;
    e->data = v;
    e->next = S;
    S = e;
}

void Stack::pop() {
    if (S) {
        slistEl* e = S;
        S = S->next;
        delete e;
    }
}

bool DFS(int v) {
    visited[v] = true;
    S.push(v);

    if (v == ve) 
        return true;

    for (int i = 0; i < N; i++) {
        if (matrix[v][i] == 1 && !visited[i])
            if (DFS(i) == true)
                return true;
    }
    S.pop();
    return false;

}

bool BFS(int vs, int ve) {
    P[vs] = -1;
    Queue kolejka = Queue();
    kolejka.push(vs);
    visited[vs] = true;

    while (!kolejka.empty()) {
        int v = kolejka.front();
        kolejka.pop();

        if (v == ve)
            return true;

        for (int i = 0; i < N; i++) {
            if (matrix[v][i] == 1 && !visited[i]) {
                kolejka.push(i);
                visited[i] = true;
                P[i] = v;
            }
        }
    }


    return false;
}

int main() {
   int v;
   vs = 1;
   ve = 6;

    cout << "DFS: " << endl;
    if (!DFS(vs)) 
        cout << "BRAK";
    else {
        while (!S.empty()) {
            cout << S.top() << " ";
            S.pop();
        }
    }
    cout << endl;

    for (int i = 0; i < N; i++)
        visited[i] = false;

    cout << "BFS: " << endl;
    if (!BFS(vs, ve)) 
        cout << "BRAK";
    else {
        v = ve;
        while (v > -1) {
            cout << v << " ";
            v = P[v];
        }
    }
    cout << endl;

    return 0;
}