//Michał Dudek
#include <iostream>

using namespace std;

int main() {

    int sesje;
    cin >> sesje;

    int wyniki[sesje];

    while (sesje) {

        int stringSize;
        int subStringLimit;

        cin >> stringSize;
        cin >> subStringLimit;

        string liczby;
        cin >> liczby;

        int jedynkiLeft = subStringLimit;
        int counter = 0;
        int max = 0;

        for (int i = 0; i < stringSize; i++) {

            counter = 0;
            jedynkiLeft = subStringLimit;

            for (int j = i; j < stringSize; j++) {

                if (liczby[j] == '1') {
                    jedynkiLeft--;
                }

                if (jedynkiLeft < 0) {
                    counter = 0;
                    jedynkiLeft = subStringLimit;
                    continue;
                }

                counter++;
                if (counter > max) max = counter;
            }

        }
        cout << max << endl;
        sesje--;
    }

    return 0;
}
