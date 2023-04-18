#include <iostream>
#include <fstream>

using namespace std;

int main ( int argc, char *argv[]) {


    ifstream plik1(argv[1]);
    ifstream plik2(argv[2]);
    string bufor1, bufor2;


    while(getline(plik1, bufor1)) {
        getline(plik2, bufor2);
        if(bufor1 != bufor2) {
            cout << "w pierwszym pliku: " << bufor1 << endl;
            cout << "w drugim pliku: " << bufor2 << endl;
        }
    }


    plik1.close();
    plik2.close();

    return 0;
}