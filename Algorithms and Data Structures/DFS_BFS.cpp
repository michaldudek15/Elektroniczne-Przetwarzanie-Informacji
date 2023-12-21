#include <iostream>
#include <iomanip>
using namespace std;

const int MAXINT = 2147483647;
const int N = 10;
bool visited[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < N; i++) {
        if (matrix[v][i] == 1 && visited[i] == false)
            DFS(i);
    }
}

void BFS(int v) {
    Queue kolejka;
    kolejka.push(v);
    visited[v] = true;

    while (!kolejka.empty()) {
        v = kolejka.front();
        kolejka.pop();
        cout << v << " ";

        for (int i = 0; i < N; i++) {
            if (matrix[v][i] == 1 && visited[i] == false) {
                kolejka.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    cout << "DFS(1): " << endl;
    DFS(1);
    cout << endl;

    for (int i = 0; i < N; i++)
        visited[i] = false;

    cout << "BFS(1): " << endl;
    BFS(1);
    cout << endl;

    return 0;
}