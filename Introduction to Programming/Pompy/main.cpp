//Michał Dudek
#include <iostream>

using namespace std;

bool next (int teren[], int &step, int rozmiar) {

   if (teren[step] < teren[step + 1]) {
       step++;
       return true;
   }
   step++;
   return false;
}

int main() {

    // wczytanie terenu
    int rozmiar;
    cin >> rozmiar;
    int teren[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        cin >> teren[i];
    }

    // stworzenie tablicy wzniesien
    int step = 0;
    int check[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        check[i] = next(teren, step, rozmiar);
    }

    // przypadek calkowicie plaskiego terenu
    bool plaski = true;
    for (int i = 0; i < rozmiar-1; i++) {
        if (teren[i] != teren[i+1] ) plaski = false;
    }
    if (plaski) {
        cout << "1";
        return 0;
    }

    // przypadek zbocza
    bool zbocze = true;
    for (int i = 0; i < rozmiar - 1; i++) {
        if (check[i] != check[0]) zbocze = false;
    }
    if (zbocze) {
        cout << "1";
        return 0;
    }

    // przypadek dolka na poczatku terenu
    int pompy = 0;
    if (teren[0] < teren[1]) {
        check[0] = 5; // pompy zaznaczam uzywajac cyfry 5
        pompy++;
    }

    // przypadek dolka na koncu terenu
    if (teren[rozmiar-1] < teren[rozmiar-2]) {
        check[rozmiar-1] = 5;
        pompy++;
    }

    // przypadek szerokiego dolka na koncu terenu
    if (teren[rozmiar-1] == teren[rozmiar-2]) {
        for (int i = 0; i < rozmiar; i++) {
            if(teren[rozmiar-1] < teren[rozmiar-2-i]) {
                check[rozmiar-1] = 5;
                pompy++;
                break;
            }
        }
    }

    bool first = true;
    for (int i = 1; i < rozmiar-2; i++) {
        if(check[i] == 0 && check[i + 1] == 1) {

            // zamontowanie pierwszej pompy
            if (first) {
                check[i + 1] = 5;
                pompy++;
                first = false;
            }

            // kolejne pompy dodaje tylko, jesli gdzies po lewej stronie terenu byl obszar wyzszy od aktualnego
            else {
                for (int j = i + 1; j > 0; j--) {
                    if (check[j] == 5) break;
                    if (teren[j] > teren[i + 1] ) {
                        check[i + 1] = 5;
                        pompy++;
                        break;
                    }
                }
            }

        }
    }

    cout << pompy;

    return 0;
}