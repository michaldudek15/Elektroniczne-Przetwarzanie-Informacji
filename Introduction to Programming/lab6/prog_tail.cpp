#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {



    string zawartosc;

    string bufor;

    while(getline(cin, bufor)) {
        zawartosc += bufor;
        zawartosc += "\n";
    }


    int liczbaLinii = atoi(argv[1]);
    int licznik = 0;

    int i = 0;


    cout << zawartosc;


    return 0;
}