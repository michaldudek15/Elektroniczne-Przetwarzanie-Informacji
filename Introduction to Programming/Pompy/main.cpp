//Michał Dudek
#include <iostream>

using namespace std;

bool next (int teren[], int &step, int rozmiar) {

   if (teren[step] < teren[step + 1]) {
       step++;
       return true;
   }
   step++;
   return false;

}

int main() {

    int rozmiar;
    cin >> rozmiar;
    int teren[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        cin >> teren[i];
    }

    int step = 0;

//    for (int i = 0; i < rozmiar; i++) {
//        cout << step << "\t" << next(teren, step, rozmiar) << endl;
//    }

    step = 0;
    int check[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        check[i] = next(teren, step, rozmiar);
    }



    bool plaski = true;

    for (int i = 0; i < rozmiar-1; i++) {
        if (teren[i] != teren[i+1] ) plaski = false;
    }

    if (plaski) {
        cout << "1";
        return 0;
    }

    bool zbocze = true;

    for (int i = 0; i < rozmiar - 1; i++) {
        if (check[i] != check[0]) zbocze = false;
    }

    if (zbocze) {
        cout << "1";
        return 0;
    }

    int pompy = 0;

    if (teren[0] < teren[1]) {
        check[0] = 5;
        pompy++;
    }
    if (teren[rozmiar-1] < teren[rozmiar-2]) {
        check[rozmiar-1] = 5;
        pompy++;
    }

    if (teren[rozmiar-1] == teren[rozmiar-2]) {
        for (int i = 0; i < rozmiar; i++) {
            if(teren[rozmiar-1] < teren[rozmiar-2-i]) {
                check[rozmiar-1] = 5;
                pompy++;
                break;
            }
        }
    }


    bool first = true;

    for (int i = 1; i < rozmiar-2; i++) {
        if(check[i] == 0 && check[i + 1] == 1) {


            if (first) {
                check[i + 1] = 5;
                pompy++;
                first = false;
            }

            else {
                for (int j = i + 1; j > 0; j--) {
                    if (check[j] == 5) break;
                    if (teren[j] > teren[i + 1] ) {
                        check[i + 1] = 5;
                        pompy++;
                        break;
                    }
                }
            }

        }
    }

//    for (int i = 0; i < rozmiar; i++) {
//        cout << i << "\t" << check[i] << endl;
//    }

    //cout << "POMPY: " << "\t" << pompy << endl;
    cout << pompy;

    return 0;
}