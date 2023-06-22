//Michal Dudek

#include <iostream>

int main() {

    // wczytanie liczby sesji
    int liczbaSesji;
    std::cin >> liczbaSesji;

    // petla sesji
    while (liczbaSesji > 0) {

        // wczytanie rozmiaru tablicy
        int rozmiarTablicy;
        std::cin >> rozmiarTablicy;
        int tab[rozmiarTablicy];

        // wczytanie elementow tablicy
        {
            int i = 0;
            while (i<rozmiarTablicy) {
                std::cin >> tab[i];
                i++;
            }
        }

        // wypisanie tablicy przed operacjami
        {
            int i = 0;
            while(i < rozmiarTablicy) {
                std::cout << tab[i] << " ";
                i++;
            }
            std::cout << std::endl;
        }

        {
            char operacja = 'A';
            int pierwszyArgument, drugiArgument, trzeciArgument;

            // petla operacji, konczy sie po wpisaniu F
            while (operacja != 'F') {
                std::cin >> operacja;

                // R – odwracanie
                if (operacja == 'R') {
                    std::cin >> pierwszyArgument; // cykliczny indeks pierwszego elementu
                    std::cin >> drugiArgument; // dlugosc pojedynczego fragmentu
                    int pamiec; // zmienna do pamietania jednego z elementow zamiany
                    int j = 1;
                    while (rozmiarTablicy - (drugiArgument * j) >= 0 && drugiArgument != 0) {
                        int i = 0;
                        while (i < drugiArgument / 2) {

                            // zapamietuje prawy element
                            pamiec = tab[(rozmiarTablicy + (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy))
                                                             % rozmiarTablicy + drugiArgument - 1) % rozmiarTablicy -
                                                            i % rozmiarTablicy))
                                         % rozmiarTablicy];


                            // lewy element wchodzi na miejsce prawego
                            tab[(rozmiarTablicy + (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy))
                                                    % rozmiarTablicy + drugiArgument - 1) % rozmiarTablicy -
                                                   i % rozmiarTablicy))
                                % rozmiarTablicy] = tab[
                                    (rozmiarTablicy + ((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy))
                                                       % rozmiarTablicy + i % rozmiarTablicy)) % rozmiarTablicy];

                            // lewy element zastepuje wartoscia z pamieci
                            tab[(rozmiarTablicy + ((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy))
                                                   % rozmiarTablicy + i % rozmiarTablicy)) % rozmiarTablicy] = pamiec;

                            i++;
                        }
                        j++;
                        // zmieniam indeks poczatkowego elementu dla kolejnego fragmentu
                        pierwszyArgument += drugiArgument;
                    }
                }

                // M - przesuniecie
                else if (operacja == 'M') {
                    std::cin >> pierwszyArgument; // cykliczny indeks pierwszego elementu
                    std::cin >> drugiArgument; // dlugosc pojedynczego fragmentu
                    std::cin >> trzeciArgument; // wartosc przesuniecia

                    int ileZostalo = rozmiarTablicy;
                    int lewyIndeks, prawyIndeks;
                    int k = 0;

                    // petla wykonuje sie tez dla niepelnowymiarowych fragmentow
                    while (ileZostalo > 0 && drugiArgument != 0) {

                        // znalezienie indeksu lewego i prawego kranca fragmentu pelnowymiarowego
                        if (ileZostalo >= drugiArgument) {
                            lewyIndeks = (rozmiarTablicy +
                                          (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy)) % rozmiarTablicy +
                                            drugiArgument * k) % rozmiarTablicy)) % rozmiarTablicy;
                            prawyIndeks = (rozmiarTablicy + ((lewyIndeks + drugiArgument - 1) % rozmiarTablicy)) %
                                          rozmiarTablicy;
                        }

                        // znalezienie indeksu lewego i prawego kranca fragmentu krotszego
                        else if (ileZostalo < drugiArgument) {
                            lewyIndeks = (rozmiarTablicy +
                                          (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy)) % rozmiarTablicy +
                                            drugiArgument * k) % rozmiarTablicy)) % rozmiarTablicy;
                            prawyIndeks = (rozmiarTablicy + ((lewyIndeks + ileZostalo - 1) % rozmiarTablicy)) %
                                          rozmiarTablicy;
                        }

                        int i = 0;
                        int pamiec;

                        // przesuniecie w prawo
                        if (trzeciArgument > 0) {
                            while (i < trzeciArgument) {
                                // zapamietuje prawy indeks
                                pamiec = tab[prawyIndeks];
                                int j = prawyIndeks;
                                while (j != lewyIndeks) {
                                    // przesuwam elementy fragmentu tablicy
                                    tab[j] = tab[(rozmiarTablicy + ((j - 1) % rozmiarTablicy)) % rozmiarTablicy];
                                    j = (rozmiarTablicy + ((j - 1) % rozmiarTablicy)) % rozmiarTablicy;
                                }
                                // podmieniam kraniec fragmentu wartoscia z pamieci
                                tab[lewyIndeks] = pamiec;
                                i++;
                            }
                        }

                        // przesuniecie w lewo
                        else if (trzeciArgument < 0) {
                            while (i < -trzeciArgument) {
                                // zapamietuje lewy indeks
                                pamiec = tab[lewyIndeks];
                                int j = lewyIndeks;
                                while (j != prawyIndeks) {
                                    // przesuwam elementy fragmentu tablicy
                                    tab[j] = tab[(rozmiarTablicy + ((j + 1) % rozmiarTablicy)) % rozmiarTablicy];
                                    j = (rozmiarTablicy + ((j + 1) % rozmiarTablicy)) % rozmiarTablicy;
                                }
                                // podmieniam kraniec fragmentu wartoscia z pamieci
                                tab[prawyIndeks] = pamiec;
                                i++;
                            }
                        }
                        ileZostalo -= drugiArgument;
                        k++;
                    }
                }

                // C - zamiana parami
                else if (operacja == 'C') {
                    std::cin >> pierwszyArgument;
                    std::cin >> drugiArgument;

                    int j = 1;
                    int pamiec;

                    while (rozmiarTablicy - (drugiArgument * 2 * j) >= 0 && drugiArgument != 0) {
                        int i = 0;

                        while ( i < drugiArgument) {

                            // zapamietuje element z kolejnego fragmentu
                            pamiec = tab[ (rozmiarTablicy + (pierwszyArgument + i + drugiArgument) % rozmiarTablicy)
                                          % rozmiarTablicy];

                            // podmieniam element z kolejnego fragmentu elementem z aktualnego fragmentu
                            tab[ (rozmiarTablicy + (pierwszyArgument + i + drugiArgument) % rozmiarTablicy)
                            % rozmiarTablicy] = tab[(rozmiarTablicy + ( (pierwszyArgument + i) % rozmiarTablicy ))
                                                    % rozmiarTablicy];

                            // element z aktualnego fragmentu podmieniam zapamietana wartoscia
                            tab[(rozmiarTablicy + ( (pierwszyArgument + i) % rozmiarTablicy )) % rozmiarTablicy] = pamiec;
                            i++;
                        }

                        j++;

                        // przesuniecie aktualnego fragmentu o dwa fragmenty w prawo
                        pierwszyArgument = pierwszyArgument + 2 * drugiArgument;
                    }
                }

                // S - sortowanie
                else if (operacja == 'S') {
                    std::cin >> pierwszyArgument;
                    std::cin >> drugiArgument;

                    int ileZostalo = rozmiarTablicy;
                    int lewyIndeks, prawyIndeks;
                    int k = 0;

                    while (ileZostalo > 0 && drugiArgument != 0) {

                        // przypadek nieujemnej wartosci drugiego argumentu
                        if ( drugiArgument >= 0) {
                            // znalezienie indeksu lewego i prawego kranca fragmentu pelnowymiarowego
                            if (ileZostalo >= drugiArgument) {
                                lewyIndeks = (rozmiarTablicy +
                                              (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy)) % rozmiarTablicy +
                                                drugiArgument * k) % rozmiarTablicy)) % rozmiarTablicy;
                                prawyIndeks = (rozmiarTablicy + ((lewyIndeks + drugiArgument - 1) % rozmiarTablicy)) %
                                              rozmiarTablicy;
                            }

                            // znalezienie indeksu lewego i prawego kranca fragmentu krotszego
                            else if (ileZostalo < drugiArgument) {
                                lewyIndeks = (rozmiarTablicy +
                                              (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy)) % rozmiarTablicy +
                                                drugiArgument * k) % rozmiarTablicy)) % rozmiarTablicy;
                                prawyIndeks = (rozmiarTablicy + ((lewyIndeks + ileZostalo - 1) % rozmiarTablicy)) %
                                              rozmiarTablicy;
                            }
                        }

                        // przypadek ujemnej wartosci drugiego argumentu
                        else {
                            // znalezienie indeksu lewego i prawego kranca fragmentu pelnowymiarowego
                            if (ileZostalo >= -drugiArgument) {
                                lewyIndeks = (rozmiarTablicy +
                                              (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy)) % rozmiarTablicy +
                                                -drugiArgument * k) % rozmiarTablicy)) % rozmiarTablicy;
                                prawyIndeks = (rozmiarTablicy + ((lewyIndeks + -drugiArgument - 1) % rozmiarTablicy)) %
                                              rozmiarTablicy;
                            }

                            // znalezienie indeksu lewego i prawego kranca fragmentu krotszego
                            else if (ileZostalo < -drugiArgument) {
                                lewyIndeks = (rozmiarTablicy +
                                              (((rozmiarTablicy + (pierwszyArgument % rozmiarTablicy)) % rozmiarTablicy +
                                                -drugiArgument * k) % rozmiarTablicy)) % rozmiarTablicy;
                                prawyIndeks = (rozmiarTablicy + ((lewyIndeks + ileZostalo - 1) % rozmiarTablicy)) %
                                              rozmiarTablicy;
                            }
                        }

                        int pamiec;

                        // sortowanie w porzadku niemalejacym
                        if (drugiArgument >= 0) {
                            int j = lewyIndeks;

                            // sortowanie babelkowe
                            while ( j != prawyIndeks ) {
                                int b = lewyIndeks;
                                while ( b != prawyIndeks ) {
                                    if ( tab[b] > tab[(rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy] ) {
                                        pamiec = tab[(rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy];
                                        tab[(rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy] = tab[b];
                                        tab[b] = pamiec;
                                    }
                                    b = (rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy;
                                }


                                j = (rozmiarTablicy + ((j + 1) % rozmiarTablicy)) % rozmiarTablicy;
                            }

                            ileZostalo -= drugiArgument;
                        }

                        // sortowanie w porzadku malejacym
                        else if (drugiArgument < 0) {
                            int j = lewyIndeks;
                            // sortowanie babelkowe
                            while ( j != prawyIndeks ) {
                                int b = lewyIndeks;
                                while ( b != prawyIndeks ) {
                                    if ( tab[b] < tab[(rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy] ) {
                                        pamiec = tab[(rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy];
                                        tab[(rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy] = tab[b];
                                        tab[b] = pamiec;
                                    }
                                    b = (rozmiarTablicy + ((b + 1) % rozmiarTablicy)) % rozmiarTablicy;
                                }
                                j = (rozmiarTablicy + ((j + 1) % rozmiarTablicy)) % rozmiarTablicy;
                            }
                            ileZostalo -= -drugiArgument;
                        }
                        k++;
                    }
                }
            }
        }

        // wypisanie po operacjach
        {
            int i = 0;
            while(i < rozmiarTablicy) {
                std::cout << tab[i] << " ";
                i++;
            }
            std::cout << std::endl;
        }

        liczbaSesji--;
    }

    return 0;
}