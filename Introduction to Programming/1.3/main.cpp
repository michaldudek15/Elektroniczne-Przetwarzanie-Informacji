#include <iostream>
using namespace std;

int main() {
    int waga;

    cout << "podaj swoją wagę: ";
    cin >> waga;

    cout << "do 100 kg brakuje ci " << 100 - waga << " kg" << endl;

    return 0;
}
