#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;

class lab3 {
public:
    typedef void (lab3::*zadanie)();
    zadanie zadania[30];

    lab3();
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
    void zadanie27();
    void zadanie28();
    void zadanie29();
    void zadanie30();
};

lab3::lab3() {
    zadania[0] = &lab3::zadanie1;
    zadania[1] = &lab3::zadanie2;
    zadania[2] = &lab3::zadanie3;
    zadania[3] = &lab3::zadanie4;
    zadania[4] = &lab3::zadanie5;
    zadania[5] = &lab3::zadanie6;
    zadania[6] = &lab3::zadanie7;
    zadania[7] = &lab3::zadanie8;
    zadania[8] = &lab3::zadanie9;
    zadania[9] = &lab3::zadanie10;
    zadania[10] = &lab3::zadanie11;
    zadania[11] = &lab3::zadanie12;
    zadania[12] = &lab3::zadanie13;
    zadania[13] = &lab3::zadanie14;
    zadania[14] = &lab3::zadanie15;
    zadania[15] = &lab3::zadanie16;
    zadania[16] = &lab3::zadanie17;
    zadania[17] = &lab3::zadanie18;
    zadania[18] = &lab3::zadanie19;
    zadania[19] = &lab3::zadanie20;
    zadania[20] = &lab3::zadanie21;
    zadania[21] = &lab3::zadanie22;
    zadania[22] = &lab3::zadanie23;
    zadania[23] = &lab3::zadanie24;
    zadania[24] = &lab3::zadanie25;
    zadania[25] = &lab3::zadanie26;
    zadania[26] = &lab3::zadanie27;
    zadania[27] = &lab3::zadanie28;
    zadania[28] = &lab3::zadanie29;
    zadania[29] = &lab3::zadanie30;
}

void lab3::call_by_index(int index) {
    (this->*zadania[index])();
}

void lab3::zadanie1() {
    cout << "Witaj EPIcki świecie";
    // printf ("Witaj EPIcki świecie");
}

void lab3::zadanie2() {
    int bok1 = 5;
    int bok2 = 5;

    while(bok1 > 0) {
        cout << "X ";
        bok1--;
    }

    cout << endl << ("X       X");
    cout << endl << ("X       X");
    cout << endl << ("X       X") << endl;

    while(bok2 > 0) {
        cout << "X ";
        bok2--;
    }
}

void lab3::zadanie3() {
    int waga;

    cout << "podaj swoją wagę: ";
    cin >> waga;
    cout << "do 100 kg brakuje ci " << 100 - waga << " kg" << endl;
}

void lab3::zadanie4() {
    int liczba1, liczba2;
    cout << "podaj pierwszą liczbę: ";
    cin >> liczba1;
    cout << "podaj drugą liczbę: ";
    cin >> liczba2;

    cout << "suma: " << liczba1 + liczba2 << endl;
    cout << "różnica: " << liczba1 - liczba2 << endl;
    cout << "iloczyn: " << liczba1 * liczba2 << endl;
    cout << "iloraz: " << liczba1 / liczba2 << endl;

}

void lab3::zadanie5() {
    int i = 97;
    while (i < 123) {
        printf("%c: %d\n", i, i);
        i++;
    }
}

void lab3::zadanie6() {
    char litera;
    cout << "kod ASCII jakiego znaku chcesz sprawdzić? ";
    cin >> litera;
    printf("%d", litera);
}

void lab3::zadanie7() {
    int znak;
    cout << "podaj wartość znaku ASCII: ";
    cin >> znak;
    printf("ten znak odpowiada: %c", znak);
}

void lab3::zadanie8() {
    int rok;
    cout << "podaj swój rok urodzenia: ";
    cin >> rok;
    if (rok > 2005) {
        cout << "nie jesteś osobą pełnoletnią!" << endl;
    }
    else if (rok < 1913) {
        cout << "wydaje mi się, że nie żyjesz" << endl;
    }
    else{
        cout << "jesteś osobą pełnoletnią!" << endl;
    }
}

void lab3::zadanie9() {
    int liczba;
    int ustalona = 36;

    cout << "jaką liczbę wybierasz? ";
    cin >> liczba;

    if (liczba < ustalona) {
        cout << "przegrywasz!" << endl;
    }
    else {
        cout << "wygrywasz!" << endl;
    }

}

void lab3::zadanie10() {
    int liczba;
    cout << "podaj liczbę: ";
    cin >> liczba;
    if(liczba%3 == 0) {
        cout << "jest podzielna przez 3" << endl;
    }
    if(liczba%5 == 0) {
        cout << "jest podzielna przez 5" << endl;
    }
    if(liczba%7 == 0) {
        cout << "jest podzielna przez 7" << endl;
    }

}

void lab3::zadanie11() {
    int i = 1;
    while (i < 1001) {
        cout << i << endl;
        i++;
    }
}

void lab3::zadanie12() {
    int i = 1;
    int granica;
    cout << "do jakiej liczby chcesz policzyc? ";
    cin >> granica;
    while (i < granica+1) {
        cout << i << endl;
        i++;
    }
}

void lab3::zadanie13() {
    int i;
    cout << "podaj od jakiej liczby zaczynamy liczenie: ";
    cin >> i;
    while (i > 0) {
        cout << i << endl;
        i--;
    }
}

void lab3::zadanie14() {
    int liczba;
    cout << "ile X'ów chcesz wypisać? ";
    cin >> liczba;
    while (liczba > 0) {
        cout << "X ";
        liczba--;
    }
}

void lab3::zadanie15() {
    int i = 120;
    while(true) {
        printf("%c, %d\n", i, i); // zakres char: [-128, 127]
        i++;
        usleep(500000);
    }
}

void lab3::zadanie16() {
    int i = 2147483641; // zakres int: [-2147483648, 2147483647]
    while(true) {
        printf("%d\n", i);
        i++;
        usleep(500000);
    }
}

void lab3::zadanie17() {
    unsigned int i = 4294967290; // zakres unsigned int: [0, 4294967295]
    while(true) {
        printf("%u\n", i);
        i++;
        usleep(500000);
    }
}

void lab3::zadanie18() {
    int i = 97;
    while (i < 123) {
        printf("%d: %c\n", i, i);
        i++;
    }
}

void lab3::zadanie19() {
    int i = 0;
    while (i < 257) {
        printf("%c, %d\n", i, i);
        i++;
    }
}

void lab3::zadanie20() {
    string square = "■";
    string rectangle = "█";
    cout << rectangle << rectangle << rectangle << rectangle << endl;
    cout << rectangle << rectangle << rectangle << rectangle <<endl;

}

void lab3::zadanie21() {
    string sponge = "▒";
    cout << sponge << sponge << sponge << sponge << sponge << endl;
    cout << sponge << sponge << sponge << sponge << sponge << endl;
}

void lab3::zadanie22() {
    cout << "|͞͞ ͞ ͞ ͞ ͞|" << endl;
    cout << "|    |" << endl;
    cout << "|    |" << endl;
    cout << "|____|" << endl;
}

void lab3::zadanie23() {
    int x = 5;
    printf("%d\n", x);
    //printf("%d\n", x);
    printf("%p\n", &x);


}

void lab3::zadanie24() {
    int wartosc = 37;
    int wybor;
    bool flag = true;
    do {
        cout << "podaj liczbę z zakresu [0, 100]: ";
        cin >> wybor;
        if(wybor == wartosc) {
            cout << "WYGRYWASZ!" << endl;
            flag = false;
        }
        else if (wybor < wartosc){
            cout << "musisz celować wyżej" << endl;
        }
        else {
            cout << "musisz celować niżej" << endl;
        }
    }
    while (flag);
}

void lab3::zadanie25() {
    int a, b, c;
    cout << "podaj trzy boki oddzielone spacjami: " ;
    cin >> a >> b >> c;

    if ( a + b > c && a + c > b && b + c > a) cout << "można\n";
    else cout << "nie można\n";

}

void lab3::zadanie26() {
    int a, b, c;
    cout << "podaj oddzielone spacjami parametry a, b i c funkcji: ";
    cin >> a >> b >> c;
    float delta = (b*b - 4*a*c);
    cout << "delta wynosi: " << delta << endl;
    if ( a == 0 ) {
        cout << "\nto nie równanie kwadratowe, parametr a musi być różny od 0!\n";
    }
    else if ( delta == 0 ) {
        cout << "\ndelta jest równa 0, więc istnieje jedno rozwiązanie: " << ( -b) / (2*a) << endl;
    }
    else if ( delta > 0) {
        cout << "\npierwiastki tego równania to: " << ( -b - sqrt(delta) )/ ( 2 * a ) << " oraz " << ( -b + sqrt(delta) )/ ( 2 * a ) << endl;
    }
    else {
        cout << "\nbrak rozwiązań!" << endl;
    }


}

void lab3::zadanie27() {
    int a = 5;
    int b = 9;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl << endl;

    a += b;
    b = a - b;
    a -= b;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

void lab3::zadanie28() {
    int a, b;
    cout << "podaj dwie liczby nieujemne: ";
    cin >> a >> b;

    while( a != b)
        if ( a > b) a -= b;
        else b -= a;
    cout << "NWD: " << a;

}

void lab3::zadanie29() {
    int n;
    cout << "podaj liczbę: ";
    cin >> n;

    if (n <= 1) cout << "nie jest pierwsza!" << endl;

    int i = 2;
    bool flag = true;
    while (i <= sqrt(n)) {
        if (n % i == 0) flag = false;
        i++;
    }
    if (!flag) cout << "liczba nie jest pierwsza" << endl;
    else cout << "liczba jest pierwsza" << endl;
}

void lab3::zadanie30() {
    int n;
    cout << "podaj wysokość drzewka: ";
    cin >> n;

    int i = 0;
    int j = 0;
    while ( i < n) {
        while( j < (n*2 -1) ) {
            if ( j < (n-1) - i || j > (n-1) + i) {
                cout << ".";
            }
            else cout << "X";

            j++;
        }
        j = 0;
        cout << endl;
        i++;
    }

}

int main() {
    lab3 o;

    int choice;
    cout << "które zadanie pokazać? ";
    cin >> choice;
    // (o.*o.zadania[--choice])();
    o.call_by_index(--choice);


    return 0;
}