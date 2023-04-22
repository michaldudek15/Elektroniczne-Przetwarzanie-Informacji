//M D
#include <iostream>

using namespace std;

void printDivider(int columns) {
    cout << "+";
    for (int i = columns; i > 0; i--) cout << "-+";
    cout << endl;
}

void printRow(int columns) {
    cout << "|";
    for (int i = columns; i > 0; i--) cout << ".|";
    cout << endl;
}

int main () {

    int rows, columns;

    cin >> rows >> columns;

    // pierwsza linia -> __+-+-+-+ ...
    cout << "  ";
    for (int i = columns - 1; i > 0; i--) cout << "+-";
    cout << "+" << endl;

    // druga linia -> __|.|.|.|.| ...
    cout << "  |";
    for (int i = columns - 1; i > 0; i--) cout << ".|";
    cout << endl;

    // wnetrze karty
    while (rows > 1) {
        printDivider(columns);
        printRow(columns);
        rows--;
    }

    // ostatnia linia -> +-+-+-+-+- ...
    printDivider(columns);

    return 0;
}
