#include <iostream>
using namespace std;

class lab5 {
public:
    typedef void (lab5::*zadanie)();
    zadanie zadania[26];

    lab5();
    void call_by_index(int index);
    void zadanie1();
    void zadanie2();
    void zadanie3();
    void zadanie4();
    void zadanie5();
    void zadanie6();
    void zadanie7();
    void zadanie8();
    void zadanie9();
    void zadanie10();
    void zadanie11();
    void zadanie12();
    void zadanie13();
    void zadanie14();
    void zadanie15();
    void zadanie16();
    void zadanie17();
    void zadanie18();
    void zadanie19();
    void zadanie20();
    void zadanie21();
    void zadanie22();
    void zadanie23();
    void zadanie24();
    void zadanie25();
    void zadanie26();
};

lab5::lab5() {
    zadania[1] = &lab5::zadanie2;
    zadania[2] = &lab5::zadanie3;
    zadania[3] = &lab5::zadanie4;
    zadania[4] = &lab5::zadanie5;
    zadania[5] = &lab5::zadanie6;
    zadania[6] = &lab5::zadanie7;
    zadania[7] = &lab5::zadanie8;
    zadania[8] = &lab5::zadanie9;
    zadania[9] = &lab5::zadanie10;
    zadania[0] = &lab5::zadanie1;
    zadania[10] = &lab5::zadanie11;
    zadania[11] = &lab5::zadanie12;
    zadania[12] = &lab5::zadanie13;
    zadania[13] = &lab5::zadanie14;
    zadania[14] = &lab5::zadanie15;
    zadania[15] = &lab5::zadanie16;
    zadania[16] = &lab5::zadanie17;
    zadania[17] = &lab5::zadanie18;
    zadania[18] = &lab5::zadanie19;
    zadania[19] = &lab5::zadanie20;
    zadania[20] = &lab5::zadanie21;
    zadania[21] = &lab5::zadanie22;
    zadania[22] = &lab5::zadanie23;
    zadania[23] = &lab5::zadanie24;
    zadania[24] = &lab5::zadanie25;
    zadania[25] = &lab5::zadanie26;
}

void lab5::call_by_index(int index) {
    (this->*zadania[index])();
}

void lab5::zadanie1(){
    int *tab = new int[10000];
}

void lab5::zadanie2(){
    while(true) int *a = new int;
}

void lab5::zadanie3(){

    struct lista {
        string imie;
        string nazwisko;
    };

    lista osoba;
    osoba.imie = "maciej";
    osoba.nazwisko = "kowalski";

    cout << osoba.imie << endl << osoba.nazwisko;
}

void lab5::zadanie4(){

    struct wyniki {
        string pseudonim;
        string gra;
        int wynik;
    };
}

void lab5::zadanie5(){

    struct wyniki {
        string pseudonim;
        string gra;
        int wynik;
    };

    wyniki pierwszy;
    pierwszy.pseudonim = "gracz1";
    pierwszy.gra = "gra1";
    pierwszy.wynik = 129;

    pierwszy.pseudonim = "gracz2";
    pierwszy.gra = "gra2";
    pierwszy.wynik = 94;

    pierwszy.pseudonim = "gracz3";
    pierwszy.gra = "gra3";
    pierwszy.wynik = 11;

    pierwszy.pseudonim = "gracz4";
    pierwszy.gra = "gra1";
    pierwszy.wynik = 57;
}

int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

void lab5::zadanie6(){
    int argument;
    cout << "podaj argument: ";
    cin >> argument;
    cout << fibonacci(argument);
}

int min(int tab[]) {
    int min = tab[0];

    for (int i = 1; i < 5; i++) {
        if(tab[i] < min) min = tab[i];
    }
    return min;
}

void lab5::zadanie7(){
    int tab[5];
    cout << "podaj 5 wartości tablicy:\n";

    for (int i = 0; i < 5; i++) {
        cin >> tab[i];
    }

    cout << "najmniejsza podana wartość: " << min(tab);

}

int max(int tab[]) {
    int max = tab[0];

    for (int i = 1; i < 5; i++) {
        if(tab[i] > max) max = tab[i];
    }
    return max;
}

void lab5::zadanie8(){
    int tab[5];
    cout << "podaj 5 wartości tablicy:\n";

    for (int i = 0; i < 5; i++) {
        cin >> tab[i];
    }

    cout << "najwieksza podana wartość: " << max(tab);
}

int minIndex(int tab[]){
    int min = tab[0];
    int wynik = 0;

    for (int i = 1; i < 5; i++) {
        if(tab[i] < min) {
            min = tab[i];
            wynik = i;
        }
    }
    return wynik;
}

void lab5::zadanie9(){

    int tab[5];
    cout << "podaj 5 wartości tablicy:\n";

    for (int i = 0; i < 5; i++) {
        cin >> tab[i];
    }

    cout << "indeks najmniejszej wartosci: " << minIndex(tab);
}

void lab5::zadanie10(){

    int tab[10] = {11, 42, 234, 643, 234, 8, 123, 432, 23, 76};

    cout << "tablica: ";
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << "\t";
    }

    int wybor;
    cout << "\npodaj wartosc do wyszukania: ";
    cin >> wybor;

    bool flag = false;

    for (int i = 0; i < 10; i++) {
        if(tab[i] == wybor) flag = true;
    }

    if(flag) cout << "znaleziono wartosc" << endl;
    else cout << "nie znaleziono wartosci" << endl;

}

void lab5::zadanie11(){
    cout << "podaj napis: ";
    string napis;
    cin >> napis;

    int i = 0;
        while(napis[i] != 0) i++;
    cout << "napis ma długość: " << i << endl;

}

void lab5::zadanie12(){

    string ciag1, ciag2;
    cout << "podaj pierwszy ciag: ";
    cin >> ciag1;
    cout << "podaj drugi ciag: ";
    cin >> ciag2;

    int i = 0;
    bool flag = 1;
    if (ciag1.length()!=ciag2.length()) flag = 0;
    while(ciag1[i] != 0 && flag) {
        if (ciag1[i] != ciag2[i] ) flag = 0;
        i++;
    }
    if (flag) cout << "ciagi są takie same" << endl;
    else cout << "ciagi nie sa takie same" << endl;
}

void lab5::zadanie13(){
    int tab1[5], tab2[5];
    cout << "podaj wartosci pierwszej tablicy:\n";
    for(int i = 0; i<5; i++) {
        cin >> tab1[i];
    }
    cout << "podaj wartosci drugiej tablicy:\n";
    for(int i = 0; i<5; i++) {
        cin >> tab2[i];
    }

    bool flag = 1;
    for (int i = 0; i<5; i++) {
        if(tab1[i] != tab2[i] ) {
            flag = 0;
            break;
        }
    }
    if (flag) cout << "tablice są takie same";
    else cout << "tablice nie są takie same";

}

int* tabPointer(int tab[], int size){
    int copy[size];

    for (int i = 0; i < size; i++) {
        copy[i] = tab[i];
    }
    return copy;

}

void lab5::zadanie14(){
    int tab[5];
    cout << "podaj wartosci tablicy:\n";
    for ( int i = 0; i < 5; i++) {
        cin >> tab[i];
    }
    cout << "adres kopii tablicy to: " << tabPointer(tab,5);
}

void lab5::zadanie15(){
    cout << "nie do końca rozumiem polecenie" << endl;
}

void lab5::zadanie16(){

    int tab1[5], tab2[5], tab3[5];

    cout << "podaj wartosci do pierwszej tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> tab1[i];
    }

    cout << "podaj wartosci do drugiej tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> tab2[i];
    }
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ( tab1[i] == tab2[j]) {
                cout << tab1[i] << endl;
                tab3[k] = tab1[i];
                k++;
            }
        }
    }
}

void lab5::zadanie17(){

    int tab1[5], tab2[5];
    cout << "podaj wartosci do pierwszej tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> tab1[i];
    }
    cout << "podaj wartosci do drugiej tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> tab2[i];
    }
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ( tab1[i] == tab2[j]) {
                cout << "usuwam: " << tab1[i] << endl;
                tab1[i] = 0;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << tab1[i] << "\t";
    }

}

void lab5::zadanie18(){

    int tab1[5], tab2[5];
    int tab3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "podaj wartosci do pierwszej tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> tab1[i];
    }

    cout << "podaj wartosci do drugiej tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> tab2[i];
    }
    int k = 5;

    for ( int i = 0; i < 5 ; i++) {
        tab3[i] = tab1[i];
    }

    for (int i = 0; i < 5; i++) {
        bool flag = 1;
        for (int j = 0; j < k; j++) {
            if(tab2[i] == tab3[j])  {
                flag = 0;
            }
        }
        if (flag) {
            tab3[k] = tab2[i];
            k++;
        }

    }

    for (int i = 0; i<10; i++){
        cout << tab3[i] << "\t";
    }

}

void increment(int &k){
    k++;
}

void lab5::zadanie19(){
    cout << "podaj wartosc: ";
    int n;
    cin >> n;
    increment(n);
    cout << "wynik: " << n;
}

void lab5::zadanie20(){

}

void lab5::zadanie21(){

    int tab[10] = {11, 42, 234, 643, 234, 8, 123, 432, 23, 76};

    cout << "tablica przed usunieciem";
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << "\t";
    }

    cout << "\nktory element chcesz usunac? ";
    int wybor;
    cin >> wybor;

    for (int i = 0; i < 10; i++) {
         if (tab[i] == wybor) {
             for (int j = i; j<10; j++) tab[j] = tab[j+1];
             tab[9] = 0;
         }
    }

    cout << "tablica po usunieciu";
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << "\t";
    }

}

void lab5::zadanie22(){

}

void lab5::zadanie23(){

}

void lab5::zadanie24(){

}

void lab5::zadanie25(){

}

void lab5::zadanie26(){

}

int main() {

    lab5 o;
    int choice;
    cout << "które zadanie pokazać? ";
    cin >> choice;
    o.call_by_index(--choice);

    return 0;
}
