#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    Node* next;
    int data;
};

void insertFront(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode-> next = head;
    head = newNode;
}

void deleteNode(Node* &head, Node *p) {
    Node* previous = NULL;

    if(p == head) {
        head = head->next;
        delete p;
    }

    else {
        previous = head;

        while (previous->next != p) {
            previous = previous->next;
        }
        previous->next = p->next;
        delete p;
    }
}

int size(Node* p) {
    if (p == NULL) return 0;
    int size = 1;

    while (p->next != NULL) {
        p = p->next;
        size++;
    }
    return size;
}

Node* find(Node *p, int data) {
    
    // for (int i = 0; i < size(p); i++) {
    int initialSize = size(p);
    for (int i = 0; i < initialSize; i++) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void print(Node* head) {
    Node* p = head;

    for (int i = 1; i <= size(head); i++) {
        cout << i << ":\t" << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

int main() {
    Node *lista;
    lista = NULL;
    
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        insertFront(lista, rand() % 20);
    }

    cout << endl;
    print(lista);

    int value;
   
    cout << "what do you want to delete? ";
    cin >> value;
    cout << endl;

    Node *found = find(lista, value);

    if (found == NULL) cout << "there is no " << value << " in the list" << endl;
    else deleteNode (lista, found);

    cout << "size of list: " << size(lista) << endl;
    print(lista);
   
    return 0;
}