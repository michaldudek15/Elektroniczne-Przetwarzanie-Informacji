#include <iostream>
using namespace std;

/*
 * print 5x5 square
 *  * * * * *
 *  *       *
 *  *       *
 *  *       *
 *  * * * * *
 */

int main() {
    int bok1 = 5;
    int bok2 = 5;

    while(bok1 > 0) {
        cout << "X ";
        bok1--;
    }

    cout << endl << ("X       X");
    cout << endl << ("X       X");
    cout << endl << ("X       X") << endl;

    while(bok2 > 0) {
        cout << "X ";
        bok2--;
    }

    return 0;
}
