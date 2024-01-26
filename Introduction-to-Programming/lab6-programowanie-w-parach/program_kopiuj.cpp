#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {


    ifstream doOdczytu(argv[1]);
    ofstream doZapisu(argv[2]);

    string bufor;

    getline(doOdczytu, bufor);
    doZapisu << bufor;

    while (getline(doOdczytu, bufor))
        doZapisu << "\n" << bufor;
    doOdczytu.close();
    doZapisu.close();


    return 0;
}