//Michal Dudek
#include <iostream>

using namespace std;

int main() {

    // wczytanie wyrazu
    char wejscie[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cin >> wejscie;

    // policzenie dlugosci
    int dlugosc = 1;
    while (true) {
        if(wejscie[dlugosc] == 0) break;
        dlugosc++;
    }

    // powtorzenie jesli dlugosc mniejsza niz 6
    if (dlugosc < 6) {
        for (int i = 0; i < dlugosc; i++) wejscie[i+dlugosc] = wejscie[i];
    }
    while (true) {
        if(wejscie[dlugosc] == 0) break;
        dlugosc++;
    }

    // zamiana pierwszej litery na wielka
    if (wejscie[0] < 123 && wejscie[0] > 96 ) wejscie[0] -= 32;

    // dodanie wykrzyknika na poczatek
    for(int i = dlugosc; i > 0; i--) {
        wejscie[i] = wejscie[i-1];
    }
    wejscie[0] = '!';

    // zamiana 'a' na '4'
    int i = 0;
    while((i < dlugosc)) {
        if(wejscie[i] == 'a') wejscie[i] = '4';
        i++;
    }

    // zamiana 's' na '$'
    i = 0;
    while((i < dlugosc)) {
        if(wejscie[i] == 's') wejscie[i] = '$';
        i++;
    }

    // zamiana 'o' na '@'
    i = 0;
    while(i < dlugosc) {
        if(wejscie[i] == 'o') wejscie[i] = '@';
        i++;
    }

    // dodanie ilosci malych liter na koncu
    int counter = 0;
    i = 0;
    for(; i < dlugosc+1; i++) {
        if(wejscie[i] > 96 && wejscie[i] < 123) counter++;
    }
    wejscie[dlugosc+1] = counter + '0';
    cout << wejscie;
    return 0;
}
