//Michał Dudek
#include <iostream>

using namespace std;

int abs(int num) {
    return (num < 0) ? -num : num;
}

void Swap(long long int a1[32], long long int a2[32],int krawedz){
    long long int temp;
    for(int i=0;i<krawedz;i++){
        temp=a1[i];
        a1[i]=a2[i];
        a2[i]=temp;
    }
}

long long int Bareiss(long long int arr[32][32], int dim) {
    if (dim <= 0) return 0;
    long long int sign = 1;
    for (int k = 0; k < dim - 1; k++) {
        if (arr[k][k] == 0) {
            long long int m = 0;
            for (m = k + 1; m < dim; m++) {
                if (arr[m][k] != 0) {
                    Swap(arr[m], arr[k], dim);
                    sign = -sign;
                    break;
                }
            }
            if (m == dim) return 0;
        }
        for (int i = k + 1; i < dim; i++) {
            for (int j = k + 1; j < dim; j++) {
                arr[i][j] = arr[k][k] * arr[i][j] - arr[i][k] * arr[k][j];
                if (k != 0) {
                    arr[i][j] /= arr[k - 1][k - 1];
                }
            }
        }
    }
    return sign * arr[dim - 1][dim - 1];
}

int main () {

    // wczytanie krawedzi szescianu
    int krawedz;
    cin >> krawedz;
    int cube[krawedz][krawedz][krawedz];

    // wczytanie danych do szescianu
    for (int d = 0; d < krawedz; d++) {
        for (int h = 0; h < krawedz; h++) {
            for (int w = 0; w < krawedz; w++) {
                cin >> cube[d][h][w];
            }
        }
    }

    char operacja =  'A';
    while (operacja != 'E') {
        cin >> operacja;

        // C - prostopadloscian
        if (operacja == 'C') {

            // wspolrzedne l - level - poziom, v - vertical - pion, p - panel - głebokosc
            int l, v, p;
            cin >> l;
            cin >> v;
            cin >> p;

            // h - height - wysokosc - poziomy, w - width - szerokosc - piony, d - depth - glebokosc - panele
            int h, w, d;
            cin >> h;
            cin >> w;
            cin >> d;

            int suma = 0;

            if (p >= krawedz/2) p = p - d;
            if (l >= krawedz/2) l = l - h;
            if (v >= krawedz/2) v = v - w;

            for (int panel = p; panel < (p + d + 1); panel++) {
                for (int poziom = l; poziom < (l + h + 1); poziom++) {
                    for (int pion = v; pion < (v + w + 1); pion++) {
                        if(panel >= 0 && panel < krawedz && poziom >= 0 && poziom < krawedz && pion >= 0 && pion < krawedz) {
                            suma += cube[panel][poziom][pion];
                        }
                    }
                }
            }
            cout << suma << endl;
        }

        // T - czworoscian
        else if (operacja == 'T') {

            // wspolrzedne l - level - poziom, v - vertical - pion, p - panel - głebokosc
            int l, v, p;
            cin >> l;
            cin >> v;
            cin >> p;

            // dlugosc prostopadlych krawedzi
            int e;
            cin >> e;

            int suma = 0;

            if (p >= krawedz/2) p = p - e;
            if (l >= krawedz/2) l = l - e;
            if (v >= krawedz/2) v = v - e;

            for (int panel = p; panel < (p + e + 1); panel++) {
                for (int poziom = l; poziom < (l + e + 1); poziom++) {
                    for (int pion = v; pion < (v + e + 1); pion++) {
                        int odlegloscX = abs(pion - v);
                        int odlegloscY = abs(poziom - l);
                        int odlegloscZ = abs(panel - p);

                        if (odlegloscX + odlegloscY + odlegloscZ <= e) {
                            if (panel >= 0 && panel < krawedz && poziom >= 0 && poziom < krawedz && pion >= 0 && pion < krawedz) {
                                suma += cube[panel][poziom][pion];
                            }
                        }
                    }
                }
            }

            cout << suma << endl;
        }

        // O - oktal
        else if (operacja == 'O') {

            // wspolrzedne l - level - poziom, v - vertical - pion, p - panel - głebokosc
            int l, v, p;
            cin >> l;
            cin >> v;
            cin >> p;

            // dlugosc promienia
            int r;
            cin >> r;

            int suma = 0;

            if (p >= krawedz/2) p = p - r;
            if (l >= krawedz/2) l = l - r;
            if (v >= krawedz/2) v = v - r;

            for (int panel = p; panel < (p + r + 1); panel++) {
                for (int poziom = l; poziom < (l + r + 1); poziom++) {
                    for (int pion = v; pion < (v + r + 1); pion++) {
                        int odlegloscX = pion - v;
                        int odlegloscY = poziom - l;
                        int odlegloscZ = panel - p;

                        if (odlegloscX * odlegloscX + odlegloscY * odlegloscY + odlegloscZ * odlegloscZ <= r * r) {
                            if (panel >= 0 && panel < krawedz && poziom >= 0 && poziom < krawedz && pion >= 0 && pion < krawedz) {
                                suma += cube[panel][poziom][pion];
                            }
                        }
                    }
                }
            }
            cout << suma << endl;
        }

        // D - wyznacznik
        else if (operacja == 'D') {
            char plaszczyzna;
            int indeks;
            long long int wyznacznik = 0;
            long long int macierz[32][32];

            cin >> plaszczyzna ; // l, v lub p | poziom, pion lub panel
            cin >> indeks ; // indeks poziomu, pionu lub panelu

            if (plaszczyzna == 'l') {
                for (int d = 0; d < krawedz; d++) {
                        for (int w = 0; w < krawedz; w++) {
                            macierz[d][w] = cube[d][indeks][w];
                        }
                }
                wyznacznik = Bareiss(macierz, krawedz);
            }

            else if (plaszczyzna == 'v') {
                for (int d = 0; d < krawedz; d++) {
                    for (int h = 0; h < krawedz; h++) {
                            macierz[d][h] = cube[d][h][indeks];
                    }
                }
                wyznacznik = Bareiss(macierz, krawedz);
            }

            else if (plaszczyzna == 'p') {
                    for (int h = 0; h < krawedz; h++) {
                        for (int w = 0; w < krawedz; w++) {
                            macierz[h][w] = cube[indeks][h][w];
                        }
                    }
                wyznacznik = Bareiss(macierz, krawedz);
            }
            cout << wyznacznik << endl;
        }
    }
    return 0;
}