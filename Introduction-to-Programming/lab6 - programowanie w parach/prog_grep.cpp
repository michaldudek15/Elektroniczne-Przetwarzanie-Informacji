#include <iostream>
#include <fstream>

using namespace std;

int main ( int argc, char *argv[]) {

    string bufor;
    string fraza = argv[1];

        while (getline(cin, bufor))
        if(!bufor.find(fraza)) cout << bufor << "\n";

    return 0;
}