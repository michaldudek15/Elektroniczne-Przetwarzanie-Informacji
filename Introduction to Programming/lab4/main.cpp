#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class lab4 {
public:
    typedef void (lab4::*zadanie)();
    zadanie zadania[39];

    lab4();
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
    void zadanie31();
    void zadanie32();
    void zadanie33();
    void zadanie34();
    void zadanie35();
    void zadanie36();
    void zadanie37();
    void zadanie38();
    void zadanie39();

};

lab4::lab4() {
    zadania[0] = &lab4::zadanie1;
    zadania[1] = &lab4::zadanie2;
    zadania[2] = &lab4::zadanie3;
    zadania[3] = &lab4::zadanie4;
    zadania[4] = &lab4::zadanie5;
    zadania[5] = &lab4::zadanie6;
    zadania[6] = &lab4::zadanie7;
    zadania[7] = &lab4::zadanie8;
    zadania[8] = &lab4::zadanie9;
    zadania[9] = &lab4::zadanie10;
    zadania[10] = &lab4::zadanie11;
    zadania[11] = &lab4::zadanie12;
    zadania[12] = &lab4::zadanie13;
    zadania[13] = &lab4::zadanie14;
    zadania[14] = &lab4::zadanie15;
    zadania[15] = &lab4::zadanie16;
    zadania[16] = &lab4::zadanie17;
    zadania[17] = &lab4::zadanie18;
    zadania[18] = &lab4::zadanie19;
    zadania[19] = &lab4::zadanie20;
    zadania[20] = &lab4::zadanie21;
    zadania[21] = &lab4::zadanie22;
    zadania[22] = &lab4::zadanie23;
    zadania[23] = &lab4::zadanie24;
    zadania[24] = &lab4::zadanie25;
    zadania[25] = &lab4::zadanie26;
    zadania[26] = &lab4::zadanie27;
    zadania[27] = &lab4::zadanie28;
    zadania[28] = &lab4::zadanie29;
    zadania[29] = &lab4::zadanie30;
    zadania[30] = &lab4::zadanie31;
    zadania[31] = &lab4::zadanie32;
    zadania[32] = &lab4::zadanie33;
    zadania[33] = &lab4::zadanie34;
    zadania[34] = &lab4::zadanie35;
    zadania[35] = &lab4::zadanie36;
    zadania[36] = &lab4::zadanie37;
    zadania[37] = &lab4::zadanie38;
    zadania[38] = &lab4::zadanie39;
}

void lab4::call_by_index(int index) {
    (this->*zadania[index])();
}

void lab4::zadanie1() {
    string imie;
    cout << "podaj swoje imie: ";
    cin >> imie;
    cout << "Witaj " << imie;
}

void lab4::zadanie2() {
    string wyraz1, wyraz2;
    cout << "podaj dwa wyrazy: ";
    cin >> wyraz1 >> wyraz2;
    cout << wyraz1 << " " << wyraz2 << endl;
}

void lab4::zadanie3() {
    int wartosci[5];
    cout << "podaj piec wartości tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> wartosci[i];
    }
    int min = wartosci[0];
    for (int j = 1; j < 5; j++) {
        if (wartosci[j] < min) min = wartosci[j];
    }
    cout << "minimalna wartosc: " << min;
}

void lab4::zadanie4() {
    int wartosci[5];
    cout << "podaj piec wartości tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> wartosci[i];
    }
    int max = wartosci[0];
    for (int j = 1; j < 5; j++) {
        if (wartosci[j] > max) max = wartosci[j];
    }
    cout << "maksymalna wartosc: " << max;
}

void lab4::zadanie5() {
    int liczby[2];
    cout << "podaj dwie wartosci do tablicy:\n";
    cin >> liczby[0];
    cin >> liczby[1];
    cout << "suma: " << liczby[0] + liczby[1] << endl;
    cout << "roznica: " << liczby[0] - liczby[1] << endl;
    cout << "iloczyn: " << liczby[0] * liczby[1] << endl;
    cout << "iloraz: " << liczby[0] / liczby[1] << " reszta: " << liczby[0] % liczby[1];
}

void lab4::zadanie6() {
    int wartosci[5];
    cout << "podaj piec wartości tablicy:\n";
    for (int i = 0; i < 5; i++) {
        cin >> wartosci[i];
    }
    for (int i = 0; i < 5; i++) {
        if(wartosci[i]%2 == 0) wartosci[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
        cout << wartosci[i] << endl;
    }
}

void lab4::zadanie7() {
    int wartosci[10];
    cout << "podaj dziesiec wartości tablicy:\n";
    for (int i = 0; i < 10; i++) {
        cin >> wartosci[i];
    }
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += wartosci[i];
    }
    cout << "suma wartosci z tablicy wynosi: " << suma;
}

void lab4::zadanie8() {
    int tabliczka[10][10];

    for (int i = 1; i<=10;i++)
        for (int j = 1; j<=10; j++) tabliczka[i-1][j-1] = i*j;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10;j++) cout << tabliczka[i][j] << "\t";
        cout << endl;
    }
}

void lab4::zadanie9() {
    int tablica[10] = {-1, -1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1};
    cout << "podaj wartości tablicy (jeśli chcesz zakończyć, to wpisz -1):\n";
    for (int i = 0 ; i < 10 ; i++){
        cin >> tablica[i];
        if(tablica[i] == -1) break;
    }
    int licznik = 0;
    float suma = 0.0;
    for (int i = 0; i < 10 ; i++) {
        if(tablica[i]==-1) break;
        else {
            licznik++;
            suma += tablica[i];
        }
    }
    cout << "ilosc wartosci w tablicy: " << licznik << "\nsrednia wartosc w tablicy: " << suma / licznik << endl;
}

void lab4::zadanie10() {
    int x,y;
    cout << "podaj wymiary prostokata [szerokosc wysokosc]: ";
    cin >> x >> y;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) cout << "X" << " ";
        cout << endl;
    }
}

void lab4::zadanie11() {
    int wiek;
    cout << "podaj wiek: ";
    cin >> wiek;

    int wybor;
    if(wiek<18) wybor = 0;
    else if(wiek < 60) wybor = 1;
    else wybor = 2;

    switch (wybor){
        case 0:
            cout << "jestes mlody" << endl;
            break;
        case 1:
            cout << "jestes dorosly" << endl;
            break;
        case 2:
            cout << "jestes stary" << endl;
            break;
    }
}

void lab4::zadanie12(){
    int znak;
    cout << "podaj liczbe odpowiadającą twojemu znakowi zodiaku:\n"
            "1 - wodnik\n"
            "2 - ryby\n"
            "3 - baran\n"
            "4 - byk\n";
    cin >> znak;
    switch (znak){
        case 1:
            cout << "wodnik: pamiętaj, że czasami warto zaryzykować" << endl;
            break;
        case 2:
            cout << "ryby: uważaj komu wierzysz" << endl;
            break;
        case 3:
            cout << "baran: czeka cię niespodziewane spotkanie" << endl;
            break;
        case 4:
            cout << "byk: czas wprowadzić w życie zmiany, które masz w planach od dawna " << endl;
            break;
        default: cout << "error";
    }
}

void lab4::zadanie13() {
    string wyraz;
    cout << "podaj wyraz: ";
    cin >> wyraz;
    int i = 0;
    while (wyraz[i]!='\0') {
        i++;
    }
    cout << "wyraz " << wyraz << " ma " << i<< " liter";
}

void lab4::zadanie14() {
    string imie;
    cout << "podaj imie: ";
    cin >> imie;

    if(imie=="Kuba") cout << "to imię męskie";
    else if (imie =="Barnaba") cout << "to imię męskie";
    else if (imie =="Bonawentura") cout << "to imię męskie";
    else if (imie =="Kosma") cout << "to imię męskie";
    else if (imie =="Dyzma") cout << "to imię męskie";
    else if (imie =="Jarema") cout << "to imię męskie";
    else if (imie =="Lasota") cout << "to imię męskie";
    else if (imie =="Niepełka") cout << "to imię męskie";
    else if (imie =="Rokita") cout << "to imię męskie";
    else if (imie =="Zawisza") cout << "to imię męskie";
    else if (imie =="Żegota") cout << "to imię męskie";
    else if (imie[imie.length()-1]=='a') cout << "to imię żeńskie";
    else cout << "to imię męskie";
}

void lab4::zadanie15() {
    string wyraz1, wyraz2;
    cout << "podaj pierwszy wyraz: ";
    cin >> wyraz1;
    cout << "podaj drugi wyraz: ";
    cin >> wyraz2;

    if (wyraz1.length()!=wyraz2.length()) cout << "te wyrazy nie są takie same";
    bool flag = 0;
    for (int i = 0; i<wyraz1.length(); i++){
        if(wyraz1[i]!=wyraz2[i]) {
            cout << "to nie ten sam wyraz";
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "to te same wyrazy";
}

void lab4::zadanie16() {
    string wyraz;
    cout << "podaj wyraz: ";
    cin >> wyraz;

    for (int i = 0; i < wyraz.length(); i++) {
        wyraz[i] = '*';
    }
    cout << "cenzura: " << wyraz;
}

void lab4::zadanie17() {
    string slowo;
    cout << "podaj slowo: ";
    cin >> slowo;
    for (int i = 0; i<slowo.length(); i++) {
        if(slowo[i] > 96 && slowo[i] < 123) slowo[i] -= 32;
    }
    cout << "slowo wielkimi literami: " << slowo;
}

void lab4::zadanie18() {
    string slowo;
    cout << "podaj slowo: ";
    cin >> slowo;
    for (int i = 0; i<slowo.length(); i++) {
        if(slowo[i] > 64 && slowo[i] < 91) slowo[i] += 32;
    }
    cout << "slowo malymi literami: " << slowo;
}

void lab4::zadanie19() {
    string slowo;
    cout << "podaj slowo: ";
    cin >> slowo;
    for(int i = 0; i < slowo.length(); i++) {
        if(slowo[i] > 64 && slowo[i] < 91) slowo[i] += 32;
        else if(slowo[i] > 96 && slowo[i] < 123) slowo[i] -= 32;
    }
    cout << "slowo po przemianie: " << slowo;
}

void lab4::zadanie20() {
    string slowo;
    cout << "podaj slowo: ";
    cin >> slowo;
    for (int i = slowo.length()-1; i >= 0; i--) {
        cout << slowo[i];
    }
}

void lab4::zadanie21() {
    string slowo;
    cout << "podaj slowo: ";
    cin >> slowo;
    int i;
    for (i = 0; i < 10 ; i++) {
        if (slowo[i] == '\0') {
            break;
        }
    }
    for (int j = i/2; j < 10; j++) {
        slowo[j]='\0';
    }
    cout << slowo;
}

void lab4::zadanie22() {
    string slowo;
    cout << "podaj slowo: ";
    cin >> slowo;

    char kopia[slowo.length()];
    for (int i = 0; i<slowo.length(); i++){
        kopia[i] = slowo[i];
    }
    cout << slowo << endl;
    cout << kopia << endl;

}

void lab4::zadanie23() {
    string wyraz;
    cout << "podaj wyraz: ";
    cin >> wyraz;
    string dlugiWyraz = wyraz + wyraz;
    cout << "podwojony wyraz: " << dlugiWyraz;
}

void lab4::zadanie24() {
    string wyraz;
    int wynik = 0;
    cout << "podaj liczbę (kilkucyfrową): ";
    cin >> wyraz;
    for (int i = wyraz.length()-1, power = 0; i>=0; i--, power++) {
        wynik += (wyraz[i] - 48) * pow(10, power);
    }
    cout << "wynik to: " << wynik;
}

void lab4::zadanie25() {
    int liczba;
    cout << "podaj liczbe: ";
    cin >> liczba;
    //int licznik = liczba > 0 ? (int) log10( liczba) + 1 : 1;
    int licznik;
    if(liczba > 0) licznik = (int) log10(liczba) + 1;
    else licznik = 1;

    char wynik[licznik];
    cout << "licznik: " << licznik << endl;
    for (int i = licznik-1; i >= 0; i--) {
        wynik[i] = (liczba%10) + 48;
        liczba /= 10;
    }
    cout << wynik;
}

void lab4::zadanie26() {
    int liczba;
    cout << "podaj liczbe: ";
    cin >> liczba;
    cout << liczba << " dzieli sie przez:\n";
    for (int i = 2 ; i <= liczba; i++) {
        if(liczba%i==0) cout << i << endl;
    }

}

void lab4::zadanie27() {
    fstream plik;
    plik.open("imie.txt", ios::out);
    if(!plik) {
        cout << "blad tworzenia pliku";
    }
    else {
        cout << "zapisuje dane do pliku";
        plik << "Michał";
        plik.close();
    }
}

void lab4::zadanie28() {
    fstream plik;
    plik.open("sprobuj_usunac.txt", ios::out);
    if(!plik) {
        cout << "blad tworzenia bliku";
    }
    while(true);
    // u mnie się da usunąć
}

void lab4::zadanie29(){
    string nazwa;
    cout << "podaj nazwe pliku: ";
    cin >> nazwa;
    ifstream plik(nazwa); // odczyt.txt
    if(plik.is_open())
        cout << plik.rdbuf();
    plik.close();
}

void lab4::zadanie30() {
    ofstream plik("zapis.txt");
    int tab[5] = {1, 2, 3, 4, 5};
    if(plik.is_open()) {
        for (int i = 0; i < 5; i++) {
            plik << tab[i] << " ";
        }
    }
    plik.close();
}

void lab4::zadanie31() {
    ifstream plik("odczyt.txt");
    string bufor;
    string tekst[10];
    int i = 0;
    if(plik.is_open()) {
        while(getline(plik, bufor)){
            tekst[i] = bufor;
            i++;
        }
    }
    for ( int j = 0; j < 10 ; j++){
        cout << tekst[j] << endl;
    }
}

void lab4::zadanie32() {
    string nazwa;
    // /Users/michaldudek/pulpit.txt
    cout << "podaj sciezke do pliku: ";
    cin >> nazwa;

    char znak;
    ifstream plik(nazwa);
    int licznik = 0;

    while (1) {
        plik >> znak;
        if(plik.eof()) goto koniec;
        licznik++;
    }
    koniec:
    cout << "\nten plik ma " << licznik << " znakow";
    plik.close();
}

void lab4::zadanie33() {

    string nazwa;
    cout << "podaj sciezke do pliku: ";
    cin >> nazwa;

    char znak;
    int licznik = 0;
    ifstream plik(nazwa);

    while(1) {
        plik >> znak;
        if(plik.eof()) break;
        licznik++;
        if(licznik%2==1) cout << znak << endl;
    }
}

void lab4::zadanie34() {
    string nazwa;
    cout << "podaj sciezke do pliku: ";
    cin >> nazwa;

    ifstream plik(nazwa);
    string bufor;
    bool flag = true;

    while(getline(plik, bufor)){
        if(flag) {
            cout << bufor << endl;
        }
        flag = !flag;
    }
    plik.close();
}

void lab4::zadanie35() {
    string odczyt, zapis;
    cout << "podaj sciezke pliku do odczytu: ";
    cin >> odczyt;
    cout << "podaj nazwe pliku do zapisu: ";
    cin >> zapis;

    ifstream doOdczytu(odczyt);
    ofstream doZapisu(zapis);

    string bufor;

    getline(doOdczytu, bufor);
    doZapisu << bufor;

    while (getline(doOdczytu, bufor))
        doZapisu << "\n" << bufor;
    doOdczytu.close();
    doZapisu.close();

}

void lab4::zadanie36() {
    int liczba;
    cout << "podaj liczbe: ";
    cin >> liczba;

    int i = 1;
    int sum = 0;
    while(i < liczba) {
        if (liczba%i==0) sum+=i;
        i++;
    }
    if(sum==liczba) cout << liczba << " jest doskonala";
    else cout << liczba << " nie jest doskonala";
}

void lab4::zadanie37() {
    int tab[6] = {0, 0, 0, 0, 0, 0};
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        tab[rand()%6]++;
    }
    for (int i = 0; i < 6; i++) {
        cout << i+1 << " oczek wyrzucono tyle razy: " << tab[i] << endl;
    }
}

void lab4::zadanie38() {
    int tab[6] = {0, 0, 0, 0, 0, 0};
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        tab[rand()%6]++;
    }
    for (int i = 0; i < 6; i++) {
        cout << i+1 << " oczek wyrzucono tyle razy: " << tab[i] << endl;
    }
    double oczekiwana = 0;
    oczekiwana += tab[0]*1;
    oczekiwana += tab[1]*2;
    oczekiwana += tab[2]*3;
    oczekiwana += tab[3]*4;
    oczekiwana += tab[4]*5;
    oczekiwana += tab[5]*6;
    cout << "wartosc oczekiwana: " << oczekiwana/1000.0;
}

void lab4::zadanie39() {
    int tab[10];
    cout << "podaj wartosci do tablicy: ";
    for (int k = 0; k < 10; k++ ){
        cin >> tab[k];
        // 9 2 4 5 8 4 3 9 1 5
    }
    int tmp;
    for (int i = 0; i < 9 ; i++ ) {
        for (int j = 0; j < (9-i); j++) {
            if( tab[j] > tab[j+1] ) {
                // swap
                tmp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = tmp;
            }
        }
    }
    for (int k = 0; k < 10; k++ ) {
        cout << tab[k] << endl;
    }
}

int main() {
    lab4 o;

    int choice;
    cout << "które zadanie pokazać? ";
    cin >> choice;
    o.call_by_index(--choice);


    return 0;
}
