#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {


    ifstream doOdczytu(argv[2]);
    string bufor;

    int liczbaLinii = atoi(argv[1]);
    int licznik = 0;

    while(getline(doOdczytu, bufor)) licznik++;
    doOdczytu.close();

    ifstream drugiPlik(argv[2]);

    int i = 0;

    while(getline(drugiPlik, bufor)) {
        if ( i >= (licznik - liczbaLinii) ) {
            cout << bufor << endl;
        } 
        i++;

    }

    return 0;
}