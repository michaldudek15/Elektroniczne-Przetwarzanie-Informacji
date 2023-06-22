#include <iostream>

using namespace std;

struct Kwadrat {
    int* szerokosc;
    int wysokosc;

};

struct Prostokat {
    int* szerokosc;
    int wysokosc;
};

int main() {


    Kwadrat kwadrat1;
    Prostokat prostokat1;

    int* x;
    int wartosc;

    x = &wartosc;
    *x = 5;

    kwadrat1.szerokosc = x;
    prostokat1.szerokosc = x;

    cout << &kwadrat1.szerokosc;
    cout << endl;
    cout << &prostokat1.szerokosc;



    return 0;
}