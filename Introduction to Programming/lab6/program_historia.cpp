#include <iostream>
#include <fstream>

using namespace std;

int main ( int argc, char *argv[]) {


    ifstream plik("/Users/michaldudek/.zsh_history");

    int i = 1;
    string bufor;

    if(plik.is_open())
            while (getline(plik, bufor))
        cout << i++ << "\t" << bufor << "\n";
        plik.close();

    return 0;
}