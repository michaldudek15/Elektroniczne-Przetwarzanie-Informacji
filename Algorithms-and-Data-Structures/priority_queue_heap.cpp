#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

const int intMax = 2147483647;
const int maxSize = 100;

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
        int findmaxdata();
        int findmaxpriority();
        void insert(int priority, int data);
        void deletemax();
        void print();
};

PriorityQueue::PriorityQueue() {
    nodes = 0;
}

PriorityQueue::~PriorityQueue() {}

bool PriorityQueue::empty() {
    return !nodes;
}

int PriorityQueue::findmaxdata() {
    if (nodes) 
        return T[1].data;
    else 
        return intMax;
}

int PriorityQueue::findmaxpriority() {
    if (nodes) 
        return T[1].priority;
    else 
        return intMax;
}

void PriorityQueue::insert(int priority, int data) {
    int counter = 0;
    int i, j;
    nodes++;
    i = nodes;

	T[i].data = data;
    T[i].priority = priority;

    j = parent(i);

    while (i > 1 && ++counter && (T[i].priority > T[j].priority)) {
        swap(T[j], T[i]);
        i = j;
        j = i / 2;
    }
    cout << "counter: " << counter << endl;
}

void PriorityQueue::deletemax() {
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
                
                    if (T[rightChild(i)].priority > T[older].priority) 
                        older = rightChild(i);
                    }
            }

            if (p < T[older].priority) {
                swap(T[i], T[older]);
                i = older;
            }

            else i = nodes;
        }
    }
} 

int main() {
    PriorityQueue Q;
    int i, p, v;

    srand(time(NULL));

    cout << "wprowadzone elementy w postaci element:priorytet\n";
    
    for (i = 1; i <= 10; i++) {
        v = i;
        p = rand( ) % 100;
        cout << v << "|" << p << endl;
        Q.insert (p, v);
    }
    
    // cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";
    // cout << Q.T[1].data << "|" << Q.T[1].priority << endl;
    // cout << Q.T[2].data << "|" << Q.T[2].priority << endl;
    // cout << Q.T[3].data << "|" << Q.T[3].priority << endl;
    // cout << Q.T[4].data << "|" << Q.T[4].priority << endl;
    // cout << Q.T[5].data << "|" << Q.T[5].priority << endl;
    // cout << Q.T[6].data << "|" << Q.T[6].priority << endl;
    // cout << Q.T[7].data << "|" << Q.T[7].priority << endl;
    // cout << Q.T[8].data << "|" << Q.T[8].priority << endl;
    // cout << Q.T[9].data << "|" << Q.T[9].priority << endl;
    // cout << Q.T[10].data << "|" << Q.T[10].priority << endl;

    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";
    while(!Q.empty()) {
       cout << Q.findmaxdata( ) << "|" << Q.findmaxpriority( ) << endl;
       Q.deletemax();
   }

   return 0;
}