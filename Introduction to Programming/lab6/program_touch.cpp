#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    fstream plik;

    plik.open(argv[1], ios::out);

    plik.close();

    return 0;
}