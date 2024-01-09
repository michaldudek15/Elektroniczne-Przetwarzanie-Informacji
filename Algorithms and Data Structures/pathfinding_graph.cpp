#include <iostream>
#include <iomanip>
using namespace std;

const int MAXINT = 2147483647;
// const int N = 4; // ilosc wierzcholkow z zadania
const int N = 8; // ilosc wierzcholkow wlasna

struct slistEl {
    slistEl* next;
    int data;
};

slistEl** A = new slistEl * [ N ]; 
// przyklad z zadania
// bool visited[N] = {0, 0, 0, 0};

// przyklad wlasny
bool visited[N] = {0,0,0,0,0,0,0,0};

int vs, ve;

// const int m = 8; //ilość sąsiadow z zadania
 const int m = 18; // ilosc sasiadow wlasna

// przyklad z zadania
// int E[m][2] = { {0,3},{0,1},{1,2},{1,0},{2,3},{2,1},{3,2},{3,0} }; //kolejne krawędzie

// przyklad wlasny
int E[m][2] = {
    {0,1}, {0,5},
    {1,0}, {1,2},
    {2,1}, {2,3}, {2,4},
    {3,2}, {3,7},
    {4,2}, {4,7},
    {5,0}, {5,6},
    {6,5}, {6,4}, {6,7},
    {7,6}, {7,3}
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
// przyklad z zadania
// int P[N] ={-1, -1, -1, -1};

// przyklad wlasny
int P[N] = {-1, -1, -1 ,-1 ,-1, -1, -1, -1};

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
    slistEl* p;

    visited[v] = true;
    S.push(v);

    if (v == ve) 
        return true;

    for (p = A[v]; p; p = p->next) {
        if (visited[p->data] == false)
            if (DFS(p->data))
                return true;
    }
    S.pop();
    
    return false;
}

bool BFS(int vs, int ve) {
    P[vs] = -1;
    Queue Q = Queue();
    slistEl *p;
    Q.push(vs);
    visited[vs] = true;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        if (v == ve)
            return true;

        for (p = A[v]; p; p = p->next) {
            if (!visited[p->data]) {
                Q.push(p->data);
                visited[p->data] = true;
                P[p->data] = v;
            }
        }
    }

    return false;
}

int main() {
	slistEl *p;
	for(int i = 0; i < N; i++ ) {
    	A [ i ] = NULL;
    	visited [ i ] = false;
    }
    
    for(int i = 0; i < m; i++ ) {
		vs = E[i][0];
        ve = E[i][1];
		 
    	p = new slistEl;    
    	p->data = ve;          
    	p->next = A [ vs ]; 
    	A [ vs ] = p;
    }
    

    for(int  i = 0; i < N; i++ ) {
    	cout << "A [ " << i << " ] =";
    	p = A [ i ];
    	while( p )
    	{
      		cout << setw ( 3 ) << p->data;
      		p = p->next;
    	}
    	cout << endl;
    }

   int v;
   vs = 0;
   ve = 3;

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