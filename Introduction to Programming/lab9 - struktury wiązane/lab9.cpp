#include <iostream>

using namespace std;

struct Mysz {
    string imie;
};

struct Kot {
    string imie;
    Mysz* ganianaMysz;
};



int main() {

    Kot burek;
    Mysz CJ;

    CJ.imie = "C.J.";
    burek.imie = "Burrek";
    burek.ganianaMysz = &CJ;

    cout << burek.ganianaMysz->imie << endl;


    return 0;
}