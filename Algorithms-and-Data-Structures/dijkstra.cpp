#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 2147483647;
const int N = 6; // liczba wierzchołkow w grafie

int A[N][N] = {
// //0  1  2  3  4  5	
//  {0, 4, 4, 1, 0, 0}, // 0
//  {4, 0, 3, 0, 3, 0}, // 1
//  {4, 3, 0, 2, 1, 5}, // 2
//  {1, 0, 2, 0, 0, 5}, // 3
//  {0, 3, 1, 0, 0, 1}, // 4
//  {0, 0, 2, 5, 1, 0}, // 5
// };

//0  1  2  3  4  5	
 {0, 1, 0, 6, 0, 0}, // 0
 {1, 0, 1, 0, 0, 0}, // 1
 {0, 1, 0, 0, 0, 1}, // 2
 {5, 0, 0, 0, 3, 1}, // 3
 {0, 0, 0, 3, 0, 0}, // 4
 {0, 0, 1, 1, 0, 0}, // 5
};

bool visited[N] = {false, false, false, false, false, false};
int dist[N] = {0, MAX, MAX, MAX, MAX, MAX};
int previous[N] = {-1, -1, -1, -1, -1, -1};

int findMin() {
    int min = -1;
    int minDist = MAX;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false && dist[i] < minDist) {
            min = i;
            minDist = dist[min]; 
        }
            
    }

    return min;
}

int main() {
    int v = 0;

    while (v != -1) {
        visited[v] = true;
        
        for (int i = 0; i < N; i++) {
            if (A[i][v] && (visited[i] == false) && (dist[i] > (dist[v] + A[i][v]) )) {
                dist[i] = dist[v] + A[i][v];
                previous[i] = v;
            }       
        }
        v = findMin();
    }

    cout << "indeksy:\t";
    for (int i = 0; i < N; i++) {
        cout << setw(3) << i << " ";
    }
    cout << endl;

    cout << "dystans:\t";
    for (int i = 0; i < N; i++) {
        cout << setw(3) << dist[i] << " ";
    }
    cout << endl;

    cout << "poprzednicy:\t";
    for (int i = 0; i < N; i++) {
        cout << setw(3) << previous[i] << " ";
    }
    cout << endl << endl;

    v = 0;

    for (int i = 0; i < N; i++) {
        if (i != v) {
            cout << "koszt sciezki od " << v << " do " << i << ": " << dist[i] << endl;
            cout << "sciezka: ";
            
            int k = i;
            cout << k << " ";
            while (previous[k] != -1) {
                cout << previous[k] << " ";
                k = previous[k];
            }
            cout << endl;
        }
    }

    return 0;
}