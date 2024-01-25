#include <iostream>
using namespace std;

void initKMPNextTable (string p, string wzorzec) {

    int KMPNext[p.length()+1];
    KMPNext[0] = -1;
    int b = -1;

    for (int i = 1; i <= p.length(); i++) {
        while ( (b > -1) && (wzorzec[b] != p[i-1] )) {
            b = KMPNext[b];
        }
        ++b;

        if ( (i == p.length()) || (p[i] != wzorzec[b]))
            KMPNext[i] = b;
        else   
            KMPNext[i] = KMPNext[b];
    }

    for (int i = 0; i < p.length(); i++) {
        cout << i << "\t";
    }
    cout << endl;

    for (int i = 0; i < p.length(); i++) {
        cout << p[i] << "\t";
    }
    cout << endl;

    for (int i = 1; i <= p.length(); i++) {
            cout << KMPNext[i] << "\t";
        }

    int dlugoscWzorca = wzorzec.length();

    cout << endl << "indeksy wzorca w tekscie: " << endl;
        
    for (int i = 0; i <= p.length(); i++) {
        if (KMPNext[i] == dlugoscWzorca) 
            cout << i - dlugoscWzorca << " ";
    }        
}

int main() {

    string s1 = "AOAGPNMAOAGPNUIO";
    string s2 = "AGPN";

    cout << "tekst: " << s1 << endl;
    cout << "wzorzec: " << s2 << endl;

    initKMPNextTable(s1, s2);

    return 0;
}