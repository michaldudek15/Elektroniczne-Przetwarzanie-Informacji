#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

int n;     

struct slistEl {
  slistEl* next;
  int data;
};        

slistEl** A;           
bool* visited; 

class queue {
  private:
    slistEl* head;
    slistEl* tail;

  public:
    queue();   
    ~queue();    
    bool empty(void);
    int front(void);
    void push(int v);
    void pop();
};

queue::queue() {
	head = tail = NULL;
}

queue::~queue() {
	while(head) pop();
}

bool queue::empty() {
    return !head;
}

int queue::front() {
    if (head) 
        return head->data;
    else
        return MAXINT;
}

void queue::push(int v) {
	slistEl* p = new slistEl;
	p->next = NULL;
	p->data = v;
	if (tail) 
        tail->next = p;
	else
        head = p;
	tail = p;
}

void queue::pop() {
  if (head) {
    slistEl* p = head;
    head = head->next;
    if (!head)
        tail = NULL;
    delete p;
  }
}

void DFS(int v) {
	slistEl * p;

    visited[v] = true;
    cout << v << " ";
    p = A[v];

    for (p = A[v]; p; p = p->next) {
        if (visited[p->data] == false) 
            DFS(p->data);
    }

}

void BFS(int v) {
	queue Q;
	slistEl *p;

    Q.push(v);
    visited[v] = true;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        cout << v << " ";

        for (p = A[v]; p; p = p->next) {
            if (visited[p->data] == false) {
                Q.push(p->data);
                visited[p->data] = true;
            }
        }

    }
}

int main() {
	int i, vs, ve;
	slistEl *p;
	
	setlocale(LC_CTYPE, "Polish");
	
    cout << "przykład z zadania:" << endl;
	const int n = 4; //ilość wierzchołkow
	const int m = 8; //ilość sąsiadow
	
	int E[m][2] = { {0,3},{0,1},{1,2},{1,0},{2,3},{2,1},{3,2},{3,0} }; //kolejne krawędzie
	
	A = new slistEl * [ n ]; 
    visited = new bool [ n ];
	
	for( i = 0; i < n; i++ ) {
    	A [ i ] = NULL;
    	visited [ i ] = false;
    }
    
    for( i = 0; i < m; i++ ) {
		vs = E[i][0];
        ve = E[i][1];
		 
    	p = new slistEl;    
    	p->data = ve;          
    	p->next = A [ vs ]; 
    	A [ vs ] = p;
    }
    

    for( i = 0; i < n; i++ ) {
    	cout << "A [ " << i << " ] =";
    	p = A [ i ];
    	while( p )
    	{
      		cout << setw ( 3 ) << p->data;
      		p = p->next;
    	}
    	cout << endl;
    }

	cout << "Przejście grafu w głąb - DFS(0):" << endl; 
	DFS ( 0 );
	cout << endl; 
	
	for( i = 0; i < n; i++ )
    	visited [ i ] = false;
    	
    cout << "Przejście grafu wszerz - BFS(0):" << endl; 
	BFS ( 0 );
	cout << endl; 	

    cout << endl << "przykład własny: " << endl;

    const int wierzcholki = 5;
    const int sasiedzi = 12;

    int graf[sasiedzi][2] = {
        {0,1},
        {1,0}, {1,2}, {1,3},
        {2,1}, {2,3}, {2,4},
        {3,1}, {3,2}, {3,4},
        {4,2}, {4,3}};

    delete A;
    delete visited;
    delete p;

    A = new slistEl* [wierzcholki];
    visited = new bool [wierzcholki];

    for (int i = 0; i < wierzcholki; i++) {
        A[i] = NULL;
        visited[i] = false;
    }

    for (int i = 0; i < sasiedzi; i++) {
        vs = graf[i][0];
        ve = graf[i][1];
        p = new slistEl;
        p->data = ve;
        p->next = A[vs];
        A[vs] = p;
    }

    for (int i = 0; i < wierzcholki; i++) {
        cout << "A [ " << i << " ] =";
        p = A[i];
        while(p) {
            cout << setw(3) << p->data;
            p = p->next;
        }
        cout << endl;
    }

    cout << "Przejście grafu w głąb - DFS(0):" << endl; 
	DFS ( 0 );
	cout << endl; 
	
	for( i = 0; i < wierzcholki; i++ )
    	visited [ i ] = false;
    	
    cout << "Przejście grafu wszerz - BFS(0):" << endl; 
	BFS ( 0 );
	cout << endl; 

	return 0;
}
 
