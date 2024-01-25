#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {


    string nazwa;
    nazwa = argv[1]; // tutaj jest nazwa pliku

    ifstream plik(nazwa); // odczyt.txt
    if(plik.is_open())
        cout << plik.rdbuf();
    plik.close();
    
}
