//Michał Dudek
#include <iostream>

using namespace std;

void wlamanie(bool opened[], int &cena, int index) {
    cena += 500;
    opened[index] = true;
}

int main() {

    // wczytanie danych
    int liczbaSamochodow;
    cin >> liczbaSamochodow;
    int samochody[liczbaSamochodow];
    for (int i = 0; i < liczbaSamochodow; i++ ) {
        cin >> samochody[i];
    }

    // pomocnicza tablica zapisujaca czy samochod jest zamkniety
    bool opened[liczbaSamochodow];
    for (int i = 0; i < liczbaSamochodow; i++ ) {
        opened[i] = false;
    }

    int cena = 0;
    for (int i = 0; i < liczbaSamochodow; i++) {
        if (!opened[i]) {
            wlamanie (opened, cena, i); // wlamanie do pierwszego samochodu (poczatek cyklu)
            int klucz = samochody[i] - 1;
            while(!opened[klucz]) { // cykl konczy sie przy probie otwarcia otwartego samochodu
                opened[klucz] = true;
                klucz = samochody[klucz] - 1;
            }
        }
    }

    cout << cena;

    return 0;
}
