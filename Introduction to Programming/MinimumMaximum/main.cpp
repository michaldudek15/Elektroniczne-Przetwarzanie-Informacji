//Michal Dudek
#include <iostream>

using namespace std;

int main() {

    int sesje, rozmiar, next;
    int min = 0;
    int max = 0;
    cin >> sesje;

    while (sesje > 0) {
        cin >> rozmiar;
        bool first = true;
        while (rozmiar > 0) {
            cin >> next;

            if (first) {
                min = next;
                max = next;
                first = false;
            }

            if (next < min) min = next;
            if (next > max) max = next;

            rozmiar--;
        }

        cout << min << " " << max << endl;
        sesje--;
    }


    return 0;
}
