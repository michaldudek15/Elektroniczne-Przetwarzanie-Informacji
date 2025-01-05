#include <iostream>
using namespace std;

const int MAXINT = 2147483647;

struct listElement {
    listElement* next;
    int data;
};

int main() {
    listElement** A;
    listElement* p;
    int i, startVertex, endVertex;
    int liczbaWierzcholkow = 5;
    int liczbaSasiadow = 7;

    // cout << "podaj liczbe wierzcholkow i liczbe sasiadow: " << endl;
    // cin >> liczbaWierzcholkow >> liczbaSasiadow;

    A = new listElement* [liczbaWierzcholkow];

    // for (i = 0; i < liczbaWierzcholkow; i++) 
    //     A[i] = NULL;
    // for (i = 0; i < liczbaSasiadow; i++) {
    //     cout << "wprowadz sasiadow wpisujac wierzcholek startowy i koncowy: " << endl;
    //     cin >> startVertex >> endVertex;
    //     p = new listElement;
    //     p->data = endVertex;
    //     p->next = A[startVertex];
    //     A[startVertex] = p;
    // }

    int adjacencyArray[7][2] = { {0,1},{1,2},{2,1},{2,3},{4,0},{4,1},{4,3} };

    for (i = 0; i < liczbaWierzcholkow; i++) 
        A[i] = NULL;
    for (i = 0; i < liczbaSasiadow; i++) {
        p = new listElement;
        p->data = adjacencyArray[i][1];
        p->next = A[adjacencyArray[i][0]];
        A[adjacencyArray[i][0]] = p;
    }

    int stopnieWchodzace[liczbaWierzcholkow];
    for (int j = 0; j < liczbaWierzcholkow; j++) {
            stopnieWchodzace[j] = 0;
        }

    for (i = 0; i < liczbaWierzcholkow; i++) {
        cout << "sasiedzi " << i << ": ";
        p = A[i];
        while (p != NULL) {
            cout << p->data << " ";
            stopnieWchodzace[p->data]++;
            p = p->next;
        }
        cout << endl;
    }

    for (i = 0; i < liczbaWierzcholkow; i++) {
        int stopien = 0;
        cout << "stopien wychodzacy " << i << ": ";
        p = A[i];
        while (p != NULL) {
            stopien++;
            p = p->next;
        }
        cout << stopien << endl;
    }

    for (i = 0; i < liczbaWierzcholkow; i++) {
        cout << "stopien wchodzacy " << i << ": " << stopnieWchodzace[i] << endl;
    }

    delete[] A;
    return 0;
}