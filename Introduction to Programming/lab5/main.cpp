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

int main() {

    lab5 o;
    int choice;
    cout << "które zadanie pokazać? ";
    cin >> choice;
    o.call_by_index(--choice);

    return 0;
}
