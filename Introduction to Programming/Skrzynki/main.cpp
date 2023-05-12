//Michał Dudek
#include <iostream>

using namespace std;

void rozbij (bool opened[], int liczbaKluczy[], int liczbaSkrzynek, int &rozbicia) {

    int max = 0;
    int indeks = 0;

    for (int i = 0; i < liczbaSkrzynek; i++) {

        if (!opened[i]) {
            if (liczbaKluczy[i] >= max) {
                max = liczbaKluczy[i];
                indeks = i;
            }
        }
    }

    opened[indeks] = true;
    cout << "ROZBIJAM SKRZYNKE POD INDEKSEM:\t" << indeks << endl;
    rozbicia++;
}

bool koniec (bool opened[], int liczbaSkrzynek) {
    for (int i = 0; i < liczbaSkrzynek; i++) {
        if (!opened[i]) return false;
    }
    return true;
}

int main() {

    // wczytanie danych
    int liczbaSkrzynek;
    cin >> liczbaSkrzynek;
    int skrzynki[liczbaSkrzynek];
    for (int i = 0; i < liczbaSkrzynek; i++) {
        cin >> skrzynki[i];
    }

    // tablica z iloscia kluczy w skrzynkach
    int liczbaKluczy[liczbaSkrzynek];
    for (int i = 0; i < liczbaSkrzynek; i++) {
        liczbaKluczy[i] = 0;
    }

    // tablica sprawdzajaca czy skrzynka jest otwarte
    bool opened[liczbaSkrzynek];
    for (int i = 0; i < liczbaSkrzynek; i++) {
        opened[i] = false;
    }

    // policzenie liczby kluczy w skrzynkach
    for (int i = 0; i < liczbaSkrzynek; i++) {
        liczbaKluczy [skrzynki[i] - 1 ]++;
    }

    int rozbicia = 0;

    // rozbicie pierwszej skrzynki
    rozbij(opened, liczbaKluczy, liczbaSkrzynek, rozbicia);

    // jesli nie wszystkie są otwarte
    while (!koniec(opened,liczbaSkrzynek)) {


        bool otworzylem = false;

        for (int i = 0; i < liczbaSkrzynek; i++) {
            // jesli skrzynka nie jest otwarta, to sprawdz czy skrzynka z jej kluczem jest otwarta
            if (!opened[i]) {
                if (opened[ skrzynki[i] - 1 ]) {

                    opened[i] = true;
                    otworzylem = true;
                    i = -1;
                }
            }
        }

        if (!otworzylem) rozbij(opened, liczbaKluczy, liczbaSkrzynek, rozbicia);

    }




//    cout << "klucze w skrzynkach:\t";
//    for (int i = 0; i < liczbaSkrzynek; i++) {
//        cout << skrzynki[i] << "(" << liczbaKluczy[i] << ")" << "\t";
//    }
//
//    cout << endl;
//    cout << "otwarte skrzynki:\t\t";
//    for (int i = 0; i < liczbaSkrzynek; i++) {
//        cout << opened[i] << "\t\t";
//    }
//
//    cout << endl;
//    cout << "rozbicia:\t" << rozbicia;

    cout << rozbicia;

    return 0;
}
