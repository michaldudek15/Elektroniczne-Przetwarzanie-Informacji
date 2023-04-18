#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {


    ifstream doOdczytu(argv[2]);
    string bufor;

    int liczbaLinii = atoi(argv[1]);

    for ( int i = 0; i < liczbaLinii; i++ ) {
        if(getline(cin, bufor)) cout << bufor << "\n";
        
    }
    
    doOdczytu.close();

    return 0;
}