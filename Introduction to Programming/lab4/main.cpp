#include <iostream>
using namespace std;

class lab4 {
public:
    typedef void (lab4::*zadanie)();
    zadanie zadania[30];

    lab4();
    void call_by_index(int index);
    //void zadanie1();
    //void zadanie2();
    //void zadanie3();
    //void zadanie4();
    //void zadanie5();
    //void zadanie6();
    //void zadanie7();
    //void zadanie8();
    //void zadanie9();
    //void zadanie10();
    //void zadanie11();
    //void zadanie12();
    //void zadanie13();
    //void zadanie14();
    //void zadanie15();
    //void zadanie16();
    //void zadanie17();
    //void zadanie18();
    //void zadanie19();
    //void zadanie20();
    //void zadanie21();
    //void zadanie22();
    //void zadanie23();
    //void zadanie24();
    //void zadanie25();
    //void zadanie26();
    //void zadanie27();
    //void zadanie28();
    //void zadanie29();
    //void zadanie30();

};

lab4::lab4() {
    //zadania[0] = &lab3::zadanie1;
    //zadania[1] = &lab3::zadanie2;
    //zadania[2] = &lab3::zadanie3;
    //zadania[3] = &lab3::zadanie4;
    //zadania[4] = &lab3::zadanie5;
    //zadania[5] = &lab3::zadanie6;
    //zadania[6] = &lab3::zadanie7;
    //zadania[7] = &lab3::zadanie8;
    //zadania[8] = &lab3::zadanie9;
    //zadania[9] = &lab3::zadanie10;
    //zadania[10] = &lab3::zadanie11;
    //zadania[11] = &lab3::zadanie12;
    //zadania[12] = &lab3::zadanie13;
    //zadania[13] = &lab3::zadanie14;
    //zadania[14] = &lab3::zadanie15;
    //zadania[15] = &lab3::zadanie16;
    //zadania[16] = &lab3::zadanie17;
    //zadania[17] = &lab3::zadanie18;
    //zadania[18] = &lab3::zadanie19;
    //zadania[19] = &lab3::zadanie20;
    //zadania[20] = &lab3::zadanie21;
    //zadania[21] = &lab3::zadanie22;
    //zadania[22] = &lab3::zadanie23;
    //zadania[23] = &lab3::zadanie24;
    //zadania[24] = &lab3::zadanie25;
    //zadania[25] = &lab3::zadanie26;
    //zadania[26] = &lab3::zadanie27;
    //zadania[27] = &lab3::zadanie28;
    //zadania[28] = &lab3::zadanie29;
    //zadania[29] = &lab3::zadanie30;
}

void lab4::call_by_index(int index) {
    (this->*zadania[index])();
}

int main() {
    lab4 o;

    int choice;
    cout << "które zadanie pokazać? ";
    cin >> choice;
    o.call_by_index(--choice);
    return 0;
}
