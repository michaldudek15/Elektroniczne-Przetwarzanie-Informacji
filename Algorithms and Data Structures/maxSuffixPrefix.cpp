#include <iostream>

using namespace std;


string findMaxSufixPrefix (string s) {
    int *PI = new int [s.length()];
    int b = -1;
    PI[0] = b;

    for (int i = 1; i <= s.length(); i++) {
        while ( (b > -1) && (s[b] != s[i-1]))
            b = PI[b];
    PI[i] = ++b;
    }
    
    cout << "tablica PI" << endl;
    for (int i = 0; i <= s.length(); i++) {
        cout << PI[i] << " ";
    }

    return s.substr(0, b-1);
}

int main() {

    string lancuch = "AOAKPNMAOAKUAO";

    cout << lancuch << endl;
    findMaxSufixPrefix(lancuch);

    


    return 0;
}
