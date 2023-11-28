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

int ascendingArray (int tab[], int n) {
    /*
    fill array tab[] with n ascending values from 0 to n-1
    */
    for (int i = 0; i < n; i++) {
        tab[i] = i;
    }
    return 0;
}

int descendingArray (int tab[], int n) {
    /*
    fill array tab[] with n descending values from 30 to 1
    */
    for (int i = 0; i < n; i++) {
        tab[i] = n-i;
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


void insertionSort(int tab[], int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int x = tab[i];
        int j = i-1;

        while ((j >= 0) && ++counter && (tab[j] > x)) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = x;
    }
    cout << "counter: " << counter << endl;
}

int main() {
    
    const int N=100;	
    int A[N];

        cout<<"LOSOWA"<<endl;
        randomArray(A, N);
        cout<<"Tablica przed posortowaniem:"<<endl;
        print(A, N);
        insertionSort(A, N);
        cout<<"Tablica po posortowaniu:"<<endl;
        print(A, N);
        cout<<endl;

        cout << "ASCENDING ARRAY" << endl;
        ascendingArray(A, N);
        cout << "tablica przed posortowaniem:" << endl;
        print(A,N);
        insertionSort(A,N);
        cout << "tablica po posortowaniu:" << endl;
        print(A,N);
        cout << endl;

        cout << "DESCENDING ARRAY" << endl;
        descendingArray(A, N);
        cout << "tablica przed posortowaniem:" << endl;
        print(A,N);
        insertionSort(A,N);
        cout << "tablica po posortowaniu:" << endl;
        print(A,N);
        cout << endl;

    return 0;
}