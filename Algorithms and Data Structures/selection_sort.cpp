#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomArray(int tab[], int n) {
    /*
    fill array tab[] with n random values in range [0...100]
    */
    srand(time(0));
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 100;
    }
    return 0;
}

int print(int tab[], int n) {
    /*
    print array tab[] of n values
    */
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
    return 0;
}

void selectionSort(int tab[], int n) {
    int counter = 0;
    for (int i = 0; i < n-1; i++) {
        int min = tab[i];
        int k = i;
        for (int j = i+1; j < n; j++) { // search for minimal value
            counter++;
            if (tab[j] < min) {
                min = tab[j];
                k = j;
            }
        }
        if (tab[k] < tab[i]) {
            swap(tab[i], tab[k]); // move minimal value to correct place
        }
    }
    cout << "counter: " << counter << endl;
}

int main() {

    const int N=50;	
	int T[N];

	randomArray(T, N);
	cout<<"Tablica przed sortowaniem 50 elementow:"<<endl;
	cout << "oczekiwana liczba porownan: " << (N * (N-1)) / 2 << endl;
	print(T, N);
	selectionSort(T, N);
	cout<<"Tablica posortowana:"<<endl;
	print(T, N);

	cout << endl;

	randomArray(T, 2*N);
	cout<<"Tablica przed sortowaniem 100 elementow:"<<endl;
	cout << "oczekiwana liczba porownan: " << (2*N * (2*N-1)) / 2 << endl;
	print(T, 2*N);
	selectionSort(T, 2*N);
	cout<<"Tablica posortowana:"<<endl;
	print(T,2*N);

	cout << endl;

	randomArray(T, 4*N);
	cout<<"Tablica przed sortowaniem 200 elementow:"<<endl;
	cout << "oczekiwana liczba porownan: " << (4*N * (4*N-1)) / 2 << endl;
	print(T, 4*N);
	selectionSort(T, 4*N);
	cout<<"Tablica posortowana:"<<endl;
	print(T, 4*N);

    return 0;
}