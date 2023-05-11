//Michał Dudek
#include <iostream>

using namespace std;

void TriBubbleSort (int tab[], int size) {

    for (int i = 0; i < size - 2; i++) {
        for (int j = 0; j < size - 2; j++) {
            if (tab[j] > tab[j+2]) {
                int temp = tab[j];
                tab[j] = tab[j+2];
                tab[j+2] = temp;
            }
        }
    }
}

void check (int tab[], int size) {
    for (int i = 0; i < size-1; i++) {
        if (tab[i] > tab[i+1]) {
            cout << i << endl;
            return;
        }
    }
    cout << "OK" << endl;
}

int main() {


    int sesje = 0;
    cin >> sesje;

    while (sesje) {

        int size;
        cin >> size;

        int tab[size];

        for (int i = 0; i < size; i++) {
            cin >> tab[i];
        }

        TriBubbleSort(tab, size);
        check(tab, size);

        sesje--;
    }







    return 0;
}
