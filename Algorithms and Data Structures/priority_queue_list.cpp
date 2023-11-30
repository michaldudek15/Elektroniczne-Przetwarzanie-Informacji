#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 2147483647;

struct listEl {
    listEl* next;
    int priority, data;
};

class PriorityQueue {
    private:
        listEl* head;
        listEl* tail;

    public:
        PriorityQueue();      
        ~PriorityQueue();     
        bool empty (void);
        int findmaxdata (void);
        int findmaxpriority (void);
        void insert (int priority, int v);
        void deletemax (void);
};

PriorityQueue::PriorityQueue() {
    head = tail = NULL;
}

PriorityQueue::~PriorityQueue() {
    while (head) {
        deletemax();
    }
}

bool PriorityQueue::empty() {
    return !head;
}

int PriorityQueue::findmaxdata() {
    if (head) {
        return head->data;
    }
    else {
        return MAX;
    }
}

int PriorityQueue::findmaxpriority() {
    if (!head) {
        return MAX;
    }
    else {
        return head->priority;
    }
}

void PriorityQueue::insert(int priority, int v) {
    listEl* p;
    listEl* r;
    p = new listEl;
    p->next = NULL;
    p->priority = priority;
    p->data = v;

    if(!head) {
        head = tail = p;
    }
    else if (head->priority < priority) {
        p->next = head;
        head = p;
    }
    else {
        r = head;
        
        while ((r->next) && (r->next->priority >= priority)) {
            r = r->next;
        }
        p->next = r->next;
        r->next = p;
        if (!p->next) {
            tail = p;
        }
    }
}

void PriorityQueue::deletemax() {
    if (head) {
        head = head->next;

        if(!head) {
            tail = NULL;
        }
    }
}

int main() {
    PriorityQueue Q;
    int i, p, v;

    srand(time(NULL));
    
    cout << "wprowadzane elementy w postaci element:priorytet\n";

    for (i = 1; i <= 10; i++) {
        v = i;
        p = rand() % 100;
        cout  << v << "|" << p << endl;
        Q.insert(p, v);
    }

    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";

    while (!Q.empty()) {
        cout << Q.findmaxdata() << "|" << Q.findmaxpriority() << endl;
        Q.deletemax();
    }

  return 0;
} 
