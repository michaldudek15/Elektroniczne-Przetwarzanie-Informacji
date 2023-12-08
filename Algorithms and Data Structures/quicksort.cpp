#include <iostream>
#include <ctime>
#include <algorithm>
#include <unistd.h>
using namespace std;

#define MAX 100

int counter = 0;

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

void quickSort(int tab[], int leftIndex, int rightIndex) {
    int i, j, x;
    x = tab[(leftIndex + rightIndex) / 2];
    i = leftIndex;
    j = rightIndex;

    do {
        while (++counter && tab[i] < x) i++;
        while (++counter && tab[j] > x) j--;

        if (i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    } while (i < j);

    if (leftIndex < j) quickSort(tab, leftIndex, j);
    if (i < rightIndex) quickSort(tab, i, rightIndex);
}

// void badQuickSort(int tab[], int leftIndex, int rightIndex) {
//     int i, j, x;
//     x = tab[leftIndex];
//     i = leftIndex;
//     j = rightIndex;

//     do {
//         while (++counter && tab[i] < x) i++;
//         while (++counter && tab[j] > x) j--;

//         if (i <= j) {
//             swap(tab[i], tab[j]);
//             i++;
//             j--;
//         }
//     } while (i < j);

//     if (leftIndex < j) badQuickSort(tab, leftIndex, j);
//     if (i < rightIndex) badQuickSort(tab, i, rightIndex);
// }

int main() {
    int tablica[MAX];

    randomArray(tablica, MAX);
    cout << "initial array: " << endl;
    print(tablica, MAX);
    counter = 0;
    quickSort(tablica, 0, MAX - 1);
    cout << "sorted array: " << endl;
    print(tablica, MAX);
    cout << "counter: " << counter << endl;
    cout << endl;
    
    // ascendingArray(tablica, MAX);
    // cout << "initial ascending array: " << endl;
    // print(tablica, MAX);
    // counter = 0;
    // badQuickSort(tablica, 0, MAX - 1);
    // cout << "sorted ascending array: " << endl;
    // print(tablica, MAX);
    // cout << "counter: " << counter << endl;
    
    return 0;
}