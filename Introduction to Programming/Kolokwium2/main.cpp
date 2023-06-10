//Michał Dudek
#include <iostream>
using namespace std;

string szyfruj (string tekst) {
    string szyfr;
    for (int i = 0; i < tekst.length(); i++) {
            char nowyZnak = tekst[i] + 3;
            if (nowyZnak > 122) nowyZnak -= 26;
            szyfr += nowyZnak;
        }
    return szyfr;

}

string odszyfruj (string szyfr) {
    string tekst;
    for (int i = 0; i < szyfr.length(); i++) {
        char nowyZnak = szyfr[i] - 3;
        if (nowyZnak < 97) nowyZnak += 26;
        tekst += nowyZnak;
    }
    return tekst;
}

int main() {

    int sesje;
    cin >> sesje;

    while (sesje) {

        char operacja;
        cin >> operacja;

        string tekst;
        cin >> tekst;

        if (operacja == 'S') {
            cout << szyfruj(tekst) << endl;
        }

        else if (operacja == 'O') {
            cout << odszyfruj(tekst) << endl;
        }

        sesje--;
    }
    return 0;
}
