#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 2147483647;
const int MIN = -2147483647;

struct elementsList {
    elementsList* next;
    int priority, data;
};

class PriorityQueue {
    private:
        elementsList* head;
        elementsList* tail;

    public:
        PriorityQueue();      
        ~PriorityQueue();     
        bool empty();
        int findMaxData();
        int findMinData();
        int findMaxPriority();
        int findMinPriority();
        void insert(int priority, int v);
        void deleteElement();
};

PriorityQueue::PriorityQueue() {
    head = tail = NULL;
}

PriorityQueue::~PriorityQueue() {
    while (head) 
        deleteElement();
}

bool PriorityQueue::empty() {
    return !head;
}

int PriorityQueue::findMaxData() {
    if (head) 
        return head->data;

    else 
        return MAX;
}

int PriorityQueue::findMinData() {
    if (head) 
        return head->data;

    else return 
        MIN;
}

int PriorityQueue::findMaxPriority() {
    if (!head) 
        return MAX;

    else 
        return head->priority;
}

int PriorityQueue::findMinPriority() {
    if (!head) 
        return MIN;

    else
        return head->priority;
}

void PriorityQueue::insert(int priority, int v) {
    int counter = 0;
    elementsList* p;
    elementsList* r;
    p = new elementsList;
    p->next = NULL;
    p->priority = priority;
    p->data = v;

    if(!head) 
        head = tail = p;

    else if (++counter && (head->priority > priority)) {
        p->next = head;
        head = p;
    }

    else {
        r = head;

        while ((r->next) && ++counter && (r->next->priority <= priority))
            r = r->next;
        p->next = r->next;
        r->next = p;

        if (!p->next) 
            tail = p;
    }
    cout << "counter: " << counter << endl;
}

void PriorityQueue::deleteElement() {
    if (head) {
        head = head->next;

        if(!head)
            tail = NULL;
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

    // while (!Q.empty()) {
    //     cout << Q.findMaxData() << "|" << Q.findMaxPriority() << endl;
    //     Q.deleteElement();
    // }

    while (!Q.empty()) {
        cout << Q.findMinData() << "|" << Q.findMinPriority() << endl;
        Q.deleteElement();
    }

  return 0;
} 
