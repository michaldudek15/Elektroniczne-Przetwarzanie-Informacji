#include <iostream>
#include <locale.h>
using namespace std;

const int MAX = 5;
int graph[MAX][MAX];

int main() {
setlocale(LC_CTYPE, "Polish");
graph[0][1] = 1;
graph[1][2] = 1;
graph[2][1] = 1;
graph[2][3] = 1;
graph[4][0] = 1;
graph[4][1] = 1;
graph[4][3] = 1;

for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
        cout << graph[i][j] << " ";
    }
    cout << endl;
}

cout << endl;

for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
        if (j == 0)
            cout << "sąsiedzi " << i << ":" << " ";
        if (graph[i][j] == 1) 
                cout << j << " ";
    }
            cout << endl;
}
    return 0;
}