//Michał Dudek
#include <iostream>
using namespace std;

// miejsce na towar
struct Place {
    unsigned short towar;
    char etykieta[2];
};

// polka
struct Shelf {
    Place miejsca[128];
    unsigned short liczbaMiejsc;
};

// regal
struct Rack {
    Shelf polki[128];
    unsigned short liczbaPolek;
};

// magazyn
struct Warehouse {
    Rack regaly[128];
    Shelf podrecznaPolka;
    unsigned short liczbaRegalow;
};

// sklad
struct Storage {
    Warehouse magazyny[128];
    unsigned short liczbaMagazynow;
    Rack podrecznyRegal;
    Shelf podrecznaPolka;
};

Storage sklad;

void fill (short W, short R, short S, short P, unsigned short A) {
    if (W < 0 || W > 128 || R < 0 || R > 128 || S < 0 || S > 128 || P < 0 || P > 128 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // wypelnienie magazynow
    sklad.liczbaMagazynow = W;
    for (short i = 0; i < W; i++) {
        sklad.magazyny[i].liczbaRegalow = R;
        sklad.magazyny[i].podrecznaPolka.liczbaMiejsc = P;

        // wypelnienie podrecznych polek magazynow
        for (short m = 0; m < P; m++) {
            sklad.magazyny[i].podrecznaPolka.miejsca[m].towar = A;
            sklad.magazyny[i].podrecznaPolka.miejsca[m].etykieta[0] = '\0';
            sklad.magazyny[i].podrecznaPolka.miejsca[m].etykieta[1] = '\1';
        }

        // wypelnienie regalow magazynow
        for (short j = 0; j < R; j++) {
            sklad.magazyny[i].regaly[j].liczbaPolek = S;

            for (short k = 0; k < S; k++) {
                sklad.magazyny[i].regaly[j].polki[k].liczbaMiejsc = P;

                for (short l = 0; l < P; l++) {
                    sklad.magazyny[i].regaly[j].polki[k].miejsca[l].towar = A;
                    sklad.magazyny[i].regaly[j].polki[k].miejsca[l].etykieta[0] = '\0';
                    sklad.magazyny[i].regaly[j].polki[k].miejsca[l].etykieta[1] = '\0';

                }
            }
        }
    }

    // wypelnienie podrecznego regalu skladu
    sklad.podrecznyRegal.liczbaPolek = S;
    for (short i = 0; i < S; i++) {
        sklad.podrecznyRegal.polki[i].liczbaMiejsc = P;

        for (short j = 0; j < P; j++) {
            sklad.podrecznyRegal.polki[i].miejsca[j].towar = A;
            sklad.podrecznyRegal.polki[i].miejsca[j].etykieta[0] = '\0';
            sklad.podrecznyRegal.polki[i].miejsca[j].etykieta[1] = '\0';
        }
    }

    // wypelnienie podrecznej polki skladu
    sklad.podrecznaPolka.liczbaMiejsc = P;
    for (short i = 0; i < P; i++) {
        sklad.podrecznaPolka.miejsca[i].towar = A;
        sklad.podrecznaPolka.miejsca[i].etykieta[0] = '\0';
        sklad.podrecznaPolka.miejsca[i].etykieta[1] = '\0';
    }

}

void setAP (short wb, short rb, short sb, unsigned short Pe) {
    if (wb < 0 || wb > sklad.liczbaMagazynow-1 || rb < 0 || rb > sklad.magazyny[wb].liczbaRegalow-1 || sb < 0 || sb > sklad.magazyny[wb].regaly[rb].liczbaPolek-1 || Pe < 0 || Pe > 128) {
        cout << "error" << endl;
        return;
    }

    // jesli miejsce nie istnialo to dostaje 0 towaru i pusta etykiete
    for (unsigned short i = 0; i < Pe; i++) {
        if (i > sklad.magazyny[wb].regaly[rb].polki[sb].liczbaMiejsc-1) {
            sklad.magazyny[wb].regaly[rb].polki[sb].miejsca[i].towar = 0;
            sklad.magazyny[wb].regaly[rb].polki[sb].miejsca[i].etykieta[0] = '\0';
            sklad.magazyny[wb].regaly[rb].polki[sb].miejsca[i].etykieta[1] = '\0';
        }
    }
    sklad.magazyny[wb].regaly[rb].polki[sb].liczbaMiejsc = Pe;
}

void setAS (short wb, short rb, short Se, unsigned short Pe) {
    if (wb < 0 || wb > sklad.liczbaMagazynow - 1 || rb < 0 || rb > sklad.magazyny[wb].liczbaRegalow - 1 || Se < 0 || Se > 128 || Pe < 0 || Pe > 128) {
        cout << "error" << endl;
        return;
    }

    // stworzenie polek w magazynie wb i regale rb
    for (short i = 0; i < Se; i++) {
        if (i > sklad.magazyny[wb].regaly[rb].liczbaPolek - 1) {
            sklad.magazyny[wb].regaly[rb].polki[i].liczbaMiejsc = Pe;
            for (int j = 0; j < Pe; j++) {
                sklad.magazyny[wb].regaly[rb].polki[i].miejsca[j].towar = 0;
                sklad.magazyny[wb].regaly[rb].polki[i].miejsca[j].etykieta[0] = '\0';
                sklad.magazyny[wb].regaly[rb].polki[i].miejsca[j].etykieta[1] = '\0';
            }
        }
        else setAP(wb, rb, i, Pe);
    }
    sklad.magazyny[wb].regaly[rb].liczbaPolek = Se;
}

void setAR (short wb, short Re, short Se, short Pe) {
    if (wb < 0 || wb > sklad.liczbaMagazynow-1 || Re < 0 || Re > 128 || Se < 0 || Se > 128 || Pe < 0 || Pe > 128) {
        cout << "error" << endl;
        return;
    }

    // stworzenie regalow w magazynie wb
    for (short i = 0; i < Re; i++) {
        if (i > sklad.magazyny[wb].liczbaRegalow-1) {
            sklad.magazyny[wb].regaly[i].liczbaPolek = Se;
            for (short j = 0; j < Se; j++) {
                sklad.magazyny[wb].regaly[i].polki[j].liczbaMiejsc = Pe;
                for (short k = 0; k < Pe; k++) {
                    sklad.magazyny[wb].regaly[i].polki[j].miejsca[k].towar = 0;
                    sklad.magazyny[wb].regaly[i].polki[j].miejsca[k].etykieta[0] = '\0';
                    sklad.magazyny[wb].regaly[i].polki[j].miejsca[k].etykieta[1] = '\0';
                }
            }
        }
        else setAS(wb, i, Se, Pe);
    }
    sklad.magazyny[wb].liczbaRegalow = Re;
}

void setAW (short We, short Re, short Se, short Pe) {
    if (We < 0 || We > 128 || Re < 0 || Re > 128 || Se < 0 || Se > 128 || Pe < 0 || Pe > 128) {
        cout << "error" << endl;
        return;
    }

    // stworzenie magazynow w skladzie
    for (short i = 0; i < We; i++) {
        if (i > sklad.liczbaMagazynow-1) {
            sklad.magazyny[i].liczbaRegalow = Re;
            for (short j = 0; j < Re; j++) {
                sklad.magazyny[i].regaly[j].liczbaPolek = Se;
                for (short k = 0; k < Se; k++) {
                    sklad.magazyny[i].regaly[j].polki[k].liczbaMiejsc = Pe;
                    for (short l = 0; l < Pe; l++) {
                        sklad.magazyny[i].regaly[j].polki[k].miejsca[l].towar = 0;
                        sklad.magazyny[i].regaly[j].polki[k].miejsca[l].etykieta[0] = '\0';
                        sklad.magazyny[i].regaly[j].polki[k].miejsca[l].etykieta[0] = '\0';
                    }
                }
            }
        }
        else setAR(i, Re, Se, Pe);
    }
    sklad.liczbaMagazynow = We;
}

void setHW (short w, short P) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || P < 0 || P > 128) {
        cout << "error" << endl;
        return;
    }

    // stworzenie miejsc w podrecznej polce magazynu w
    for (short i = 0; i < P; i++) {
        if (i > sklad.magazyny[w].podrecznaPolka.liczbaMiejsc-1) {
            sklad.magazyny[w].podrecznaPolka.miejsca[i].towar = 0;
            sklad.magazyny[w].podrecznaPolka.miejsca[i].etykieta[0] = '\0';
            sklad.magazyny[w].podrecznaPolka.miejsca[i].etykieta[1] = '\0';
        }
    }
    sklad.magazyny[w].podrecznaPolka.liczbaMiejsc = P;
}

void setHR (short S, short P) {
    if (S < 0 || S > 128 || P < 0 || P > 128) {
        cout << "error" << endl;
        return;
    }

    // stworzenie miejsc w podrecznym regale skladu
    for (short i = 0; i < S; i++) {
        if (i > sklad.podrecznyRegal.liczbaPolek-1) {
            sklad.podrecznyRegal.polki[i].liczbaMiejsc = P;
            for (short j = 0; j < P; j++) {
                sklad.podrecznyRegal.polki[i].miejsca[j].towar = 0;
                sklad.podrecznyRegal.polki[i].miejsca[j].etykieta[0] = '\0';
                sklad.podrecznyRegal.polki[i].miejsca[j].etykieta[1] = '\0';
            }
        }
        else {
            for (short j = 0; j < P; j++) {
                if (j > sklad.podrecznyRegal.polki[i].liczbaMiejsc-1) {
                    sklad.podrecznyRegal.polki[i].miejsca[j].towar = 0;
                    sklad.podrecznyRegal.polki[i].miejsca[j].etykieta[0] = '\0';
                    sklad.podrecznyRegal.polki[i].miejsca[j].etykieta[1] = '\0';
                }
            }
            sklad.podrecznyRegal.polki[i].liczbaMiejsc = P;
        }
    }
    sklad.podrecznyRegal.liczbaPolek = S;
}

void setHS (short P) {
    if (P < 0 || P > 128) {
        cout << "error" << endl;
        return;
    }

    // stworzenie miejsc w podrecznej polce skladu
    for (int i = 0; i < P; i++) {
        if (i > sklad.podrecznaPolka.liczbaMiejsc - 1) {
            sklad.podrecznaPolka.miejsca[i].towar = 0;
            sklad.podrecznaPolka.miejsca[i].etykieta[0] = '\0';
            sklad.podrecznaPolka.miejsca[i].etykieta[1] = '\0';
        }
    }
    sklad.podrecznaPolka.liczbaMiejsc = P;
}

void putW (short w, short r, short s, short p, unsigned short A) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || r < 0 || r > sklad.magazyny[w].liczbaRegalow-1 || s < 0 || s > sklad.magazyny[w].regaly[r].liczbaPolek-1 || p < 0 || p > sklad.magazyny[w].regaly[r].polki[s].liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    // dodanie A towaru do miejsca w magazynie
    if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar + A > 65535) sklad.magazyny[w].regaly[r].polki[r].miejsca[p].towar = 65535;
    else sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar += A;
}

void putH (short w, short p, unsigned short A) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || p < 0 || p > sklad.magazyny[w].podrecznaPolka.liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // dodanie towaru do podrecznej polki magazynu
    if (sklad.magazyny[w].podrecznaPolka.miejsca[p].towar + A > 65535) sklad.magazyny[w].podrecznaPolka.miejsca[p].towar = 65535;
    else sklad.magazyny[w].podrecznaPolka.miejsca[p].towar += A;
}

void putR (short s, short p, unsigned short A) {
    if (s < 0 || s > sklad.podrecznyRegal.liczbaPolek-1 || p < 0 || p > sklad.podrecznyRegal.polki[s].liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // dodanie towaru do podrecznego regalu skladu
    if (sklad.podrecznyRegal.polki[s].miejsca[p].towar + A > 65535) sklad.podrecznyRegal.polki[s].miejsca[p].towar = 65535;
    else sklad.podrecznyRegal.polki[s].miejsca[p].towar += A;
}

void putS (short p, unsigned short A) {
    if (p < 0 || p > sklad.podrecznaPolka.liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // dodanie towaru do podrecznej polki skladu
    if (sklad.podrecznaPolka.miejsca[p].towar + A > 65535) sklad.podrecznaPolka.miejsca[p].towar = 65535;
    else sklad.podrecznaPolka.miejsca[p].towar += A;
}

void popW (short w, short r, short s, short p, unsigned short A) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || r < 0 || r > sklad.magazyny[w].liczbaRegalow-1 || s < 0 || s > sklad.magazyny[w].regaly[r].liczbaPolek-1 || p < 0 || p > sklad.magazyny[w].regaly[r].polki[s].liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // odjęcie A towaru z miejsca w magazynie
    if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar - A < 0) sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar = 0;
    else sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar -= A;
}

void popH (short w, short p, unsigned short A) {
    if (w < 0 || w >= sklad.liczbaMagazynow || p < 0 || p > sklad.magazyny[w].podrecznaPolka.liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // odjecie A towaru z podrecznej polki magazynu
    if (sklad.magazyny[w].podrecznaPolka.miejsca[p].towar - A < 0) sklad.magazyny[w].podrecznaPolka.miejsca[p].towar = 0;
    else sklad.magazyny[w].podrecznaPolka.miejsca[p].towar -= A;
}

void popR (short s, short p, unsigned short A) {
    if (s < 0 || s > sklad.podrecznyRegal.liczbaPolek-1 || p < 0 || p > sklad.podrecznyRegal.polki[s].liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // odjecie A towaru z podrecznego regalu magazynu
    if (sklad.podrecznyRegal.polki[s].miejsca[p].towar - A < 0) sklad.podrecznyRegal.polki[s].miejsca[p].towar = 0;
    else sklad.podrecznyRegal.polki[s].miejsca[p].towar -= A;
}

void popS (short p, unsigned short A) {
    if (p < 0 || p > sklad.podrecznaPolka.liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    // odjecie A towaru z podrecznej polki skladu
    if (sklad.podrecznaPolka.miejsca[p].towar - A < 0) sklad.podrecznaPolka.miejsca[p].towar = 0;
    else sklad.podrecznaPolka.miejsca[p].towar -= A;
}

void movW (short wb, short rb, short sb, short we, short re, short se, short p, unsigned short A) {
    if (wb < 0 || wb >= sklad.liczbaMagazynow || rb < 0 || rb >= sklad.magazyny[wb].liczbaRegalow || sb < 0 || sb >= sklad.magazyny[wb].regaly[rb].liczbaPolek || we < 0 || we >= sklad.liczbaMagazynow || re < 0 || re >= sklad.magazyny[we].liczbaRegalow || se < 0 || se >= sklad.magazyny[we].regaly[re].liczbaPolek || p < 0 || p >= sklad.magazyny[we].regaly[re].polki[se].liczbaMiejsc || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    unsigned short ware = A;

    // przesuniecie towaru miedzy magazynami
    if (sklad.magazyny[wb].regaly[rb].polki[sb].miejsca[p].towar < A) ware = sklad.magazyny[wb].regaly[rb].polki[sb].miejsca[p].towar;
    if (sklad.magazyny[we].regaly[re].polki[se].miejsca[p].towar + ware > 65535) ware = 65535 - sklad.magazyny[we].regaly[re].polki[se].miejsca[p].towar;

    sklad.magazyny[wb].regaly[rb].polki[sb].miejsca[p].towar -= ware;
    sklad.magazyny[we].regaly[re].polki[se].miejsca[p].towar += ware;
}

void movH (short w, short r, short s, short p, unsigned short A) {
    if (w < 0 || w >= sklad.liczbaMagazynow || r < 0 || r >= sklad.magazyny[w].liczbaRegalow || s < 0 || s >= sklad.magazyny[w].regaly[r].liczbaPolek || p < 0 || p >= sklad.magazyny[w].regaly[r].polki[s].liczbaMiejsc || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    unsigned short ware = A;

    // przesuniecie towaru miedzy magazynem i podreczna polka
    if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar < A) ware = sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar;
    if (sklad.magazyny[w].podrecznaPolka.miejsca[p].towar + ware > 65535) ware = 65535 - sklad.magazyny[w].podrecznaPolka.miejsca[p].towar;

    sklad.magazyny[w].regaly[r].polki[s].miejsca[p].towar -= ware;
    sklad.magazyny[w].podrecznaPolka.miejsca[p].towar += ware;
}

void movR (short w, short r, short sb, short se, short p, unsigned short A) {
    if (w < 0 || w >= sklad.liczbaMagazynow || r < 0 || r >= sklad.magazyny[w].liczbaRegalow || sb < 0 || sb >= sklad.magazyny[w].regaly[r].liczbaPolek || se < 0 || se >= sklad.podrecznyRegal.liczbaPolek || p < 0 || p >= sklad.podrecznyRegal.polki[se].liczbaMiejsc || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    unsigned short ware = A;

    // przesuniecie towaru miedzy magazynem a podrecznym regalem skladu
    if (sklad.magazyny[w].regaly[r].polki[sb].miejsca[p].towar < A) ware = sklad.magazyny[w].regaly[r].polki[sb].miejsca[p].towar;
    if (sklad.podrecznyRegal.polki[se].miejsca[p].towar + ware > 65535) ware = 65535 - sklad.podrecznyRegal.polki[se].miejsca[p].towar;

    sklad.magazyny[w].regaly[r].polki[sb].miejsca[p].towar -= ware;
    sklad.podrecznyRegal.polki[se].miejsca[p].towar += ware;
}

void movS (short s, short p, unsigned short A) {
    if (s < 0 || s > sklad.podrecznyRegal.liczbaPolek-1 || p < 0 || p > sklad.podrecznyRegal.polki[s].liczbaMiejsc-1 || A < 0 || A > 65535) {
        cout << "error" << endl;
        return;
    }

    unsigned short ware = A;

    // przesuniecie powaru miedzy podrecznym regalem a podreczna polka skladu
    if (sklad.podrecznyRegal.polki[s].miejsca[p].towar < A) ware = sklad.podrecznyRegal.polki[s].miejsca[p].towar;
    if (sklad.podrecznaPolka.miejsca[p].towar + ware > 65535) ware = 65535 - sklad.podrecznaPolka.miejsca[p].towar;

    sklad.podrecznyRegal.polki[s].miejsca[p].towar -= ware;
    sklad.podrecznaPolka.miejsca[p].towar += ware;
}

void getE () {
    long long int sumaTowaru = 0;

    // zebranie sumy z magazynow
    for (int i = 0; i < sklad.liczbaMagazynow; i++) {
        for (int j = 0; j < sklad.magazyny[i].liczbaRegalow; j++) {
            for (int k = 0; k < sklad.magazyny[i].regaly[j].liczbaPolek; k++) {
                for (int l = 0; l < sklad.magazyny[i].regaly[j].polki[k].liczbaMiejsc; l++) {
                    sumaTowaru += sklad.magazyny[i].regaly[j].polki[k].miejsca[l].towar;
                }
            }
        }
    }

    // zebranie sumy z podrecznych polek magazynow
    for (int i = 0; i < sklad.liczbaMagazynow; i++) {
        for (int j = 0; j < sklad.magazyny[i].podrecznaPolka.liczbaMiejsc; j++) {
            sumaTowaru += sklad.magazyny[i].podrecznaPolka.miejsca[j].towar;
        }
    }

    // zebranie sumy z podrecznego regalu
    for (int i = 0; i < sklad.podrecznyRegal.liczbaPolek; i++) {
        for (int j = 0; j < sklad.podrecznyRegal.polki[i].liczbaMiejsc; j++) {
            sumaTowaru += sklad.podrecznyRegal.polki[i].miejsca[j].towar;
        }
    }

    // zebranie sumy z podrecznej polki
    for (int i = 0; i < sklad.podrecznaPolka.liczbaMiejsc; i++) {
        sumaTowaru += sklad.podrecznaPolka.miejsca[i].towar;
    }

    cout << sumaTowaru << endl;
}

void getW (short w) {
    if (w < 0 || w > sklad.liczbaMagazynow-1) {
        cout << "error" << endl;
        return;
    }

    long long int sumaTowaru = 0;

    // zebranie sumy z magazynu
    for (unsigned short i = 0; i < sklad.magazyny[w].liczbaRegalow; i++) {
        for (unsigned short j = 0; j < sklad.magazyny[w].regaly[i].liczbaPolek; j++) {
            for (unsigned short k = 0; k < sklad.magazyny[w].regaly[i].polki[j].liczbaMiejsc; k++) {
                sumaTowaru += sklad.magazyny[w].regaly[i].polki[j].miejsca[k].towar;
            }
        }
    }

    // zebranie sumy z podrecznej polki
    for (unsigned short i = 0; i < sklad.magazyny[w].podrecznaPolka.liczbaMiejsc; i++) sumaTowaru += sklad.magazyny[w].podrecznaPolka.miejsca[i].towar;

    cout << sumaTowaru << endl;
}

void getRW (short w, short r) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || r < 0 || r > sklad.magazyny[w].liczbaRegalow-1) {
        cout << "error" << endl;
        return;
    }

    long long int sumaTowaru = 0;

    // zebranie sumy z regalu magazynu
    for (unsigned short i = 0; i < sklad.magazyny[w].regaly[r].liczbaPolek; i++) {
        for (unsigned short j = 0; j < sklad.magazyny[w].regaly[r].polki[i].liczbaMiejsc; j++) {
            sumaTowaru += sklad.magazyny[w].regaly[r].polki[i].miejsca[j].towar;
        }
    }

    cout << sumaTowaru << endl;
}

void getRH () {
    long long int sumaTowaru = 0;

    // zebranie sumy z podrecznego regalu skladu
    for (unsigned short i = 0; i < sklad.podrecznyRegal.liczbaPolek; i++) {
        for (unsigned short j = 0; j < sklad.podrecznyRegal.polki[i].liczbaMiejsc; j++) {
            sumaTowaru += sklad.podrecznyRegal.polki[i].miejsca[j].towar;
        }
    }

    cout << sumaTowaru << endl;
}

void getSW (short w, short r, short s) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || r < 0 || r > sklad.magazyny[w].liczbaRegalow-1 || s < 0 || s >= sklad.magazyny[w].regaly[r].liczbaPolek) {
        cout << "error" << endl;
        return;
    }

    long long int sumaTowaru = 0;

    // zebranie sumy z polki regalu magazynu
    for (unsigned short i = 0; i < sklad.magazyny[w].regaly[r].polki[s].liczbaMiejsc; i++) sumaTowaru += sklad.magazyny[w].regaly[r].polki[s].miejsca[i].towar;

    cout << sumaTowaru << endl;
}

void getSH (short w) {
    if (w < 0 || w > sklad.liczbaMagazynow-1) {
        cout << "error" << endl;
        return;
    }

    long long int sumaTowaru = 0;

    // zebranie sumy z podrecznej polki magazynu
    for (unsigned short i = 0; i < sklad.magazyny[w].podrecznaPolka.liczbaMiejsc; i++) sumaTowaru += sklad.magazyny[w].podrecznaPolka.miejsca[i].towar;

    cout << sumaTowaru << endl;
}

void getSR (short s) {
    if (s < 0 || s > sklad.podrecznyRegal.liczbaPolek-1) {
        cout << "error" << endl;
        return;
    }

    long long int sumaTowaru = 0;

    // zebranie sumy z podrecznego regalu skladu
    for (unsigned short i = 0; i < sklad.podrecznyRegal.polki[s].liczbaMiejsc; i++) sumaTowaru += sklad.podrecznyRegal.polki[s].miejsca[i].towar;

    cout << sumaTowaru << endl;
}

void getS () {
    long long int sumaTowaru = 0;

    // zebranie sumy z podrecznej polki skladu
    for (unsigned short i = 0; i < sklad.podrecznaPolka.liczbaMiejsc; i++) sumaTowaru += sklad.podrecznaPolka.miejsca[i].towar;

    cout << sumaTowaru << endl;
}

void setLW (short w, short r, short s, short p) {
    char nowaEtykieta[2];
    cin >> nowaEtykieta[0] >> nowaEtykieta[1];

    if (w < 0 || w > sklad.liczbaMagazynow-1 || r < 0 || r > sklad.magazyny[w].liczbaRegalow-1 || s < 0 || s > sklad.magazyny[w].regaly[r].liczbaPolek-1 || p < 0 || p > sklad.magazyny[w].regaly[r].polki[s].liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    if (nowaEtykieta[0] < 48 || nowaEtykieta[0] > 57 || nowaEtykieta[1] < 48 || nowaEtykieta[1] > 57) {
        cout << "error" << endl;
        return;
    }

    // nadanie nowej etykiety w miejscu
    sklad.magazyny[w].regaly[r].polki[s].miejsca[p].etykieta[0] = nowaEtykieta[0];
    sklad.magazyny[w].regaly[r].polki[s].miejsca[p].etykieta[1] = nowaEtykieta[1];
}

void setLH (short w, short p) {
    char nowaEtykieta[2];
    cin >> nowaEtykieta[0] >> nowaEtykieta[1];

    if (w < 0 || w > sklad.liczbaMagazynow-1 || p < 0 || p > sklad.magazyny[w].podrecznaPolka.liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    if (nowaEtykieta[0] < 48 || nowaEtykieta[0] > 57 || nowaEtykieta[1] < 48 || nowaEtykieta[1] > 57) {
        cout << "error" << endl;
        return;
    }

    // nadanie nowej etykiety w podrecznej polce magazynu
    sklad.magazyny[w].podrecznaPolka.miejsca[p].etykieta[0] = nowaEtykieta[0];
    sklad.magazyny[w].podrecznaPolka.miejsca[p].etykieta[1] = nowaEtykieta[1];
}

void setLR (short s, short p) {
    char nowaEtykieta[2];
    cin >> nowaEtykieta[0] >> nowaEtykieta[1];

    if (s < 0 || s > sklad.podrecznyRegal.liczbaPolek-1 || p < 0 || p > sklad.podrecznyRegal.polki[s].liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    if (nowaEtykieta[0] < 48 || nowaEtykieta[0] > 57 || nowaEtykieta[1] < 48 || nowaEtykieta[1] > 57) {
        cout << "error" << endl;
        return;
    }

    // nadanie nowej etykiety w podrecznym regale skladu
    sklad.podrecznyRegal.polki[s].miejsca[p].etykieta[0] = nowaEtykieta[0];
    sklad.podrecznyRegal.polki[s].miejsca[p].etykieta[1] = nowaEtykieta[1];
}

void setLS (short p) {
    char nowaEtykieta[2];
    cin >> nowaEtykieta[0] >> nowaEtykieta[1];

    if (p < 0 || p > sklad.podrecznaPolka.liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    if (nowaEtykieta[0] < 48 || nowaEtykieta[0] > 57 || nowaEtykieta[1] < 48 || nowaEtykieta[1] > 57) {
        cout << "error" << endl;
        return;
    }

    // nadanie nowej etykiety w podrecznej polce skladu
    sklad.podrecznaPolka.miejsca[p].etykieta[0] = nowaEtykieta[0];
    sklad.podrecznaPolka.miejsca[p].etykieta[1] = nowaEtykieta[1];
}

void getLW (short w, short r, short s, short p) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || r < 0 || r > sklad.magazyny[w].liczbaRegalow-1 || s < 0 || s > sklad.magazyny[w].regaly[r].liczbaPolek-1 || p < 0 || p > sklad.magazyny[w].regaly[r].polki[s].liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    // wypisanie etykiety miejsca w magazynie
    if (sklad.magazyny[w].regaly[r].polki[s].miejsca[p].etykieta[0] == '\0' && sklad.magazyny[w].regaly[r].polki[s].miejsca[p].etykieta[1] == '\0') cout << "--" << endl;
    else cout << sklad.magazyny[w].regaly[r].polki[s].miejsca[p].etykieta[0] << sklad.magazyny[w].regaly[r].polki[s].miejsca[p].etykieta[1] << endl;
}

void getLH (short w, short p) {
    if (w < 0 || w > sklad.liczbaMagazynow-1 || p < 0 || p > sklad.magazyny[w].podrecznaPolka.liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    // wypisanie etykiety z podrecznej polki
    if (sklad.magazyny[w].podrecznaPolka.miejsca[p].etykieta[0] == '\0' && sklad.magazyny[w].podrecznaPolka.miejsca[p].etykieta[1] == '\0') cout << "--" << endl;
    else cout << sklad.magazyny[w].podrecznaPolka.miejsca[p].etykieta[0] << sklad.magazyny[w].podrecznaPolka.miejsca[p].etykieta[1] << endl;
}

void getLR (short s, short p) {
    if (s < 0 || s > sklad.podrecznyRegal.liczbaPolek-1 || p < 0 || p > sklad.podrecznyRegal.polki[s].liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    // wypisanie etykiety z podrecznego regalu
    if (sklad.podrecznyRegal.polki[s].miejsca[p].etykieta[0] == '\0' && sklad.podrecznyRegal.polki[s].miejsca[p].etykieta[1] == '\0') cout << "--" << endl;
    else cout << sklad.podrecznyRegal.polki[s].miejsca[p].etykieta[0] << sklad.podrecznyRegal.polki[s].miejsca[p].etykieta[1] << endl;
}

void getLS (short p) {
    if (p < 0 || p > sklad.podrecznaPolka.liczbaMiejsc-1) {
        cout << "error" << endl;
        return;
    }

    // wypisanie etykiety z podrecznej polki skladu
    if (sklad.podrecznaPolka.miejsca[p].etykieta[0] == '\0' && sklad.podrecznaPolka.miejsca[p].etykieta[1] == '\0') cout << "--" << endl;
    else cout << sklad.podrecznaPolka.miejsca[p].etykieta[0] << sklad.podrecznaPolka.miejsca[p].etykieta[1] << endl;
}

int main() {

    char polecenie[7] = {'S', 'T', 'A', 'R', 'T', '\0', '\0'};

    do {
        cin >> polecenie;

        if (polecenie[0] == 'F' && polecenie[1] == 'I' && polecenie[2] == 'L' && polecenie[3] == 'L') {
            short W, R, S, P;
            unsigned short A;
            cin >> W >> R >> S >> P >> A;
            fill(W, R, S, P, A);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'A' && polecenie[5] == 'P') {
            short wb, rb, sb;
            unsigned short Pe;
            cin >> wb >> rb >> sb >> Pe;
            setAP(wb, rb, sb, Pe);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'A' && polecenie[5] == 'S') {
            short wb, rb, Se;
            unsigned short Pe;
            cin >> wb >> rb >> Se >> Pe;
            setAS(wb, rb, Se, Pe);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'A' && polecenie[5] == 'R') {
            short wb, Re, Se, Pe;
            cin >> wb >> Re >> Se >> Pe;
            setAR(wb, Re, Se, Pe);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'A' && polecenie[5] == 'W') {
            short We, Re, Se, Pe;
            cin >> We >> Re >> Se >> Pe;
            setAW(We, Re, Se, Pe);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'H' && polecenie[5] == 'W') {
            short w, P;
            cin >> w >> P;
            setHW(w, P);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'H' && polecenie[5] == 'R') {
            short S, P;
            cin >> S >> P;
            setHR(S, P);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'H' && polecenie[5] == 'S') {
            short P;
            cin >> P;
            setHS(P);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[4] == 'W') {
            short w, r, s, p;
            unsigned short A;
            cin >> w >> r >> s >> p >> A;
            putW(w, r, s, p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[4] == 'H') {
            short w, p;
            unsigned short A;
            cin >> w >> p >> A;
            putH(w, p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[4] == 'R') {
            short s, p;
            unsigned short A;
            cin >> s >> p >> A;
            putR(s, p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'U' && polecenie[2] == 'T' && polecenie[4] == 'S') {
            short p;
            unsigned short A;
            cin >> p >> A;
            putS(p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[4] == 'W') {
            short w, r, s, p;
            unsigned short A;
            cin >> w >> r >> s >> p >> A;
            popW(w, r, s, p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[4] == 'H') {
            short w, p;
            unsigned short A;
            cin >> w >> p >> A;
            popH(w, p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[4] == 'R') {
            short s, p;
            unsigned short A;
            cin >> s >> p >> A;
            popR(s, p, A);
        }

        else if (polecenie[0] == 'P' && polecenie[1] == 'O' && polecenie[2] == 'P' && polecenie[4] == 'S') {
            short p;
            unsigned short A;
            cin >> p >> A;
            popS(p, A);
        }

        else if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[4] == 'W') {
            short wb, rb, sb, we, re, se, p;
            unsigned short A;
            cin >> wb >> rb >> sb >> we >> re >> se >> p >> A;
            movW(wb, rb, sb, we, re, se, p, A);
        }

        else if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[4] == 'W') {
            short w, r, s, p;
            unsigned short A;
            cin >> w >> r >> s >> p >> A;
            movH(w, r, s, p, A);
        }

        else if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[4] == 'R') {
            short w, r, sb, se, p;
            unsigned short A;
            cin >> w >> r >> sb >> se >> p >> A;
            movR(w, r, sb, se, p , A);
        }

        else if (polecenie[0] == 'M' && polecenie[1] == 'O' && polecenie[2] == 'V' && polecenie[4] == 'S') {
            short s, p;
            unsigned short A;
            cin >> s >> p >> A;
            movS(s, p, A);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'E') {
            getE();
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'W') {
            short w;
            cin >> w;
            getW(w);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'R' && polecenie[5] == 'W') {
            short w, r;
            cin >> w >> r;
            getRW(w, r);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'R' && polecenie[5] == 'H') {
            getRH();
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'S' && polecenie[5] == 'W') {
            short w, r, s;
            cin >> w >> r >> s;
            getSW(w, r, s);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'S' && polecenie[5] == 'H') {
            short w;
            cin >> w;
            getSH(w);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'S' && polecenie[5] == 'R') {
            short s;
            cin >> s;
            getSR(s);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'S') {
            getS();
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'W') {
            short w, r, s, p;
            cin >> w >> r >> s >> p;
            setLW(w, r, s, p);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'H') {
            short w, p;
            cin >> w >> p;
            setLH(w, p);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'R') {
            short s, p;
            cin >> s >> p;
            setLR(s, p);
        }

        else if (polecenie[0] == 'S' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'S') {
            short p;
            cin >> p;
            setLS(p);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'W') {
            short w, r, s, p;
            cin >> w >> r >> s >> p;
            getLW(w, r, s, p);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'H') {
            short w, p;
            cin >> w >> p;
            getLH(w, p);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'R') {
            short s, p;
            cin >> s >> p;
            getLR(s, p);
        }

        else if (polecenie[0] == 'G' && polecenie[1] == 'E' && polecenie[2] == 'T' && polecenie[4] == 'L' && polecenie[5] == 'S') {
            short p;
            cin >> p;
            getLS(p);
        }


    } while ( !(polecenie[0] == 'E' && polecenie[1] == 'N' && polecenie[2] == 'D') );

    return 0;
}
