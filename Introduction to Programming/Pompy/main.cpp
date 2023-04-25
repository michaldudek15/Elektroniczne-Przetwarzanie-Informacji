//Michal Dudek
#include <iostream>

using namespace std;

void szukajDolu(int *i, int teren[]) {
    //(*i)++;
}

void przejdzDoKonca(int *i, int teren[]) {
    while(true){
        if(teren[*i+1] != teren[*i]) {
            cout << "wychodze: " << *i << endl;
            break;
        }
        i++;
    }
}

void szukajSzczytu(int *i, int teren[]) {
    i++;
}

int main() {

    int rozmiar;
    cin >> rozmiar;

    int teren[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        cin >> teren[i];
    }

    cout << "teren: ";

    for (int i = 0; i < rozmiar; i++) {
        cout << teren[i] << " ";
    }
    cout << endl;

    int pompy = 1;

    int i;
    for(i = 0; i < rozmiar; i++) {
        przejdzDoKonca(&i, teren);
        szukajDolu(&i, teren);
        przejdzDoKonca(&i, teren);
        szukajSzczytu(&i, teren);
    }


    return 0;
}
