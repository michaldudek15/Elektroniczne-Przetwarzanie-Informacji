//Michał Dudek
#include <iostream>

using namespace std;

bool hack (string &atak) {

    for (int i = (atak.size() - 2); i >= 0; i--) {
        if (atak[i] == 'L' && atak[i+1] == 'S') {
            atak[i] = 'S';
            atak[i+1] = 'L';
            return true; // jesli sie uda zhakować zwraca true
        }
    }
    return false; // jesli sie nie uda zwraca false
}

int test (string atak) {
    int power = 1;
    int damage = 0;

    for (int i = 0; i < atak.size(); i++) {
        if (atak[i] == 'L') power *= 2;
        if (atak[i] == 'S') damage += power;
    }
    return damage;
}

int main() {

   int sesje;
   cin >> sesje;

   while (sesje) {

       int HP;
       cin >> HP;

       string atak;
       cin >> atak;

       int licznik = 0;
       bool mozliwe = true;


       while (test(atak) > HP) {
           if(!hack(atak)) {
           mozliwe = false;
           break;
           }
           else {
               licznik++;
           }
       }

       if (mozliwe) cout << licznik << endl;
       else cout << "NIEMOZLIWE" << endl;

       sesje--;
   }

    return 0;
}
