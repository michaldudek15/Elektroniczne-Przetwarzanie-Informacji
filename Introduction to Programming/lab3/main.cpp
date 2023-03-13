#include <iostream>
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
};

lab3::lab3() {
    zadania[0] = &lab3::zadanie1;
    zadania[1] = &lab3::zadanie2;
    zadania[2] = &lab3::zadanie3;
    zadania[3] = &lab3::zadanie4;
    zadania[4] = &lab3::zadanie5;
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
    char litera;
    cout << "kod ASCII jakiej litery chcesz sprawdzić? ";
    cin >> litera;
    printf("%d", litera);
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
