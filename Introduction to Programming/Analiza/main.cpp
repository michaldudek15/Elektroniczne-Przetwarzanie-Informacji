//Michał Dudek
#include <iostream>

using namespace std;

int main() {

    int litery = 0;
    int aktualny = 0;
    int najdluzszy = 0;
    int wyrazy = 1;
    string tekst, bufor;

    // wczytanie calego tekstu do stringa
    while (getline(cin, bufor)) {
        tekst += bufor;
        tekst += ' ';
        if (bufor.size() > najdluzszy) najdluzszy = bufor.size();
    }

    // zamiana tabulacji na spacje
    for (int i = 0; i < tekst.size(); i++) {
        if (tekst[i] == '\t') tekst[i] = ' ';
    }

    // usuniecie nadmiarowych spacji
    string final;
    for (int i = 0; i < tekst.length();  ){
        if (tekst[i] == ' '){
            if (i == 0 || i == tekst.length() - 1){
                i++;
                continue;
            }
            while (tekst[i + 1] == ' ')
                i++;
        }
        final += tekst[i++];
    }

    // liczenie liter i wyrazow
    for (int i = 0; i < final.size(); i++) {
        if (final[i] >= 65 && final[i] <= 90 || final[i] >= 97 && final[i] <= 122) litery++;
        if (final[i] == ' ') wyrazy++;
    }

    // wypisanie wyniku
    if (litery == 0) wyrazy = 0;
    cout << litery << " " << wyrazy << " " << najdluzszy;
    
    return 0;
}
