#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

const int intMax = 2147483647;
const int maxSize = 101;
int globalCounter = 0;

int parent(int i) {
    return i/2;
}

int leftChild(int i) {
    return 2*i;
}

int rightChild(int i) {
    return 2*i + 1;
}

struct QueueEl{
    int priority, data;
};

class PriorityQueue {
    private:
        int nodes;

    public:
        QueueEl T[maxSize];
        PriorityQueue();
        ~PriorityQueue();
        bool empty();
        int findmindata();
        int findminpriority();
        void insert(int priority, int data);
        void deletemin();
        void print();
};

PriorityQueue::PriorityQueue() {
    nodes = 0;
}

PriorityQueue::~PriorityQueue() {}

bool PriorityQueue::empty() {
    return !nodes;
}

int PriorityQueue::findmindata() {
    if (nodes) return T[1].data;
    else return intMax;
}

int PriorityQueue::findminpriority() {
    if (nodes) return T[1].priority;
    else return intMax;
}

void PriorityQueue::insert(int priority, int data) {
    int i, j;
    nodes++;
    i = nodes;

	T[i].data = data;
    T[i].priority = priority;

    j = parent(i);

    while (i > 1 && ++globalCounter && (T[i].priority < T[j].priority)) {
        swap(T[j], T[i]);
        i = j;
        j = i / 2;
    }
}

void PriorityQueue::deletemin() {
    int i, d, p, older;

        p = T[nodes].priority;
        d = T[nodes].data;
        nodes--;

    if (nodes > 0) {

        i = 1;
        T[i].priority = p;
        T[i].data = d;

        while (i < nodes) {

            if (leftChild(i) <= nodes) {
                older = leftChild(i);

                if (rightChild(i) <= nodes) {
                
                    if (T[rightChild(i)].priority < T[older].priority) 
                        older = rightChild(i);
                    }
            }

            if (p > T[older].priority) {
                swap(T[i], T[older]);
                i = older;
            }

            else i = nodes;
        }
    }
} 

int main() {
    PriorityQueue Q1;
    int i, p, v;

    srand(time(NULL));

    globalCounter = 0;
    cout << "wprowadzone losowe priorytety\n";
    for (i = 1; i <= 100; i++) {
        v = i;
        p = rand( ) % 100;
        cout << p << " ";
        Q1.insert (p, v);
    }
    cout << endl;
    cout << "posortowane losowe priorytety\n";
    while(!Q1.empty()) {
       cout << Q1.findminpriority( ) << " ";
       Q1.deletemin();
   }
    cout << endl << "counter: " << globalCounter << endl << endl;

    PriorityQueue Q2;
    globalCounter = 0;
    cout << "wprowadzone posortowane rosnaca priorytety\n";
    for (i = 1; i <= 100; i++) {
        v = i;
        p = i;
        cout << p << " ";
        Q2.insert (p, v);
    }
    cout << endl;
    cout << "posortowane rosnace priorytety\n";
    while(!Q2.empty()) {
       cout << Q2.findminpriority( ) << " ";
       Q2.deletemin();
   }
    cout << endl << "counter: " << globalCounter << endl << endl;

    PriorityQueue Q3;
    globalCounter = 0;
    cout << "wprowadzone posortowane malejaca priorytety\n";
    for (i = 100; i > 0; i--) {
        v = i;
        p = i;
        cout << p << " ";
        Q3.insert (p, v);
    }
    cout << endl;
    cout << "posortowane malejace priorytety\n";
    while(!Q3.empty()) {
       cout << Q3.findminpriority( ) << " ";
       Q3.deletemin();
   }
    cout << endl << "counter: " << globalCounter << endl << endl;

   return 0;
}