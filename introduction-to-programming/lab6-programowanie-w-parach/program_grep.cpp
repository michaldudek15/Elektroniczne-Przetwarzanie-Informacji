#include <iostream>
#include <fstream>

using namespace std;

int main ( int argc, char *argv[]) {


    ifstream plik(argv[2]);
    string bufor;
    string fraza = argv[1];

    if(plik.is_open())
            while (getline(plik, bufor))
        if(!bufor.find(fraza)) cout << bufor << "\n";
        plik.close();

    return 0;
}