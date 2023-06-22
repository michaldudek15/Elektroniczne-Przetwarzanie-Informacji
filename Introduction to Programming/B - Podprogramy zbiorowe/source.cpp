//Michal Dudek
#include <iostream>
using namespace std;

// funkcje i procedury pomocnicze
int size (int set[]) {
    int size = 0;
    while (true) {
        if(set[size] == -1) break;
        size++;
    }
    return size;
}

void print (int set[]) {
    for (int i = 0; i < size(set); i++) {
        cout << set[i] << "\t";
    }
    cout << endl;
}

void sort (int set[]) {
    int temp;
    for (int i = 0; i < size(set) - 1; i++){
        for (int j = 0; j < size(set) - 1 - i; j++) {
            if (set[j] > set[j+1]) {
                temp = set[j];
                set[j] = set[j+1];
                set[j+1] = temp;
            }
        }
    }
}

void swap (int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition (int arr[], int low, int high, int pivot){
    int i = low;
    int j = low;
    while ( i <= high){
        if (arr[i] > pivot){
            i++;
        }
        else{
            swap(arr,i,j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort (int arr[], int low, int high){
    if (low < high){
        int pivot = arr[high];
        int pos = partition (arr, low, high, pivot);
        quickSort (arr, low, pos-1);
        quickSort (arr, pos+1, high);
    }
}

bool universum (int value) {
    if (value < 1 || value > 4095) return false;
    else return true;
}

// funkcje i procedury do zadania
bool Equal (int set1[], int set2[]) {

    int n = size(set1);

    if (n != size(set2)) return false;

    for (int i = 0; i < n; i++){
        bool flag = 0;
        for (int j = 0; j < n; j++) {
            if (set1[i] == set2[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) return false;
    }

    return true;
}

bool Empty (int set[]) {
    if (size(set) == 0) return true;
    else return false;
}

bool Nonempty (int set[]) {
    if (size(set) != 0) return true;
    else return false;
}

bool Element (int element, int set[]) {
    if (Empty(set)) return false;

    for (int i = 0; i < size(set); i++) {
        if (element == set[i]) return true;
    }

    return false;
}

void Add (int value, int set[]) {

    if (!universum(value)) return;
    else if ( Element(value, set)) return;

    else {
        set[size(set) + 1] = -1;
        set[size(set)] = value;
    }

    //sort(set);
    quickSort(set, 0, size(set)-1);
}

void Create (int ilosc, int tablica[], int set[]) {

    int k = 0;
    for (int i = 0; i < ilosc; i++) {
        if(universum(tablica[i])) {
            if (!Element(tablica[i], set)) {
                set[k] = tablica[i];
                k++;
            }
        }
    }
    set[k] = -1;
    quickSort(set, 0, size(set) - 1);
}

void Complement (int set[], int dopelnienie[]) {

    int rozmiar = size(set);
    int N = rozmiar;
    int j = 0;
    for (int i = 1; i < 4096; i++) {
        if(rozmiar) {
            bool isIn = false;
            for (int k = 0; k < N; k++) {
                if(set[k] == i) isIn = true;
            }
            if(isIn) {
                rozmiar--;
            }
            else {
                dopelnienie[j] = i;
                j++;
            }
        }
        else {
            dopelnienie[j] = i;
            j++;
        }
    }
    dopelnienie[j] = -1;
}

void Union (int firstSet[], int secondSet[], int set[]) {

    // rozmiar pierwszego setu
    int firstSize = 0;
    while (true) {
        if (firstSet[firstSize] == -1) break;
        firstSize++;
    }

    // rozmiar drugiego setu
    int secondSize = 0;
    while (true) {
        if (secondSet[secondSize] == -1) break;
        secondSize++;
    }

    // dodaje caly pierwszy set
    int j = 0;
    for (int i = 0; i < firstSize; i++) {
        set[j] = firstSet[i];
        j++;
    }

    // dodaje te elementy drugiego, ktorych nie ma
    for (int i = 0; i < secondSize; i++) {
        bool isIn = false;
        for (int k = 0; k < j; k++) {
            if (set[k] == secondSet[i]) isIn = true;
        }
        if (!isIn) {
            set[j] = secondSet[i];
            j++;
        }
    }
    set[j] = -1;
    //sort(set);
    quickSort(set, 0, size(set)-1);
}

void Intersection (int firstSet[], int secondSet[], int set[]) {
    int k = 0;
    int firstSize = size(firstSet);
    int secondSize = size(secondSet);

    for (int i = 0; i < firstSize; i++) {
        for (int j = 0; j < secondSize; j++) {
            if(firstSet[i] == secondSet[j]) {
                set[k] = firstSet[i];
                k++;
            }
        }
    }

    set[k] = -1;
    //sort(set);
    quickSort(set, 0, size(set) - 1);
}

void Difference (int firstSet[], int secondSet[], int set[]) {

    int k = 0;
    int firstSize = size(firstSet);
    int secondSize = size(secondSet);

    for (int i = 0; i < firstSize; i++) {

        bool isIn = false;
        for (int j = 0; j < secondSize; j++) {
            if (firstSet[i] == secondSet[j]) isIn = true;
        }

        if(!isIn) {
            set[k] = firstSet[i];
            k++;
        }
    }

    set[k] = -1;
    quickSort(set, 0, size(set) - 1);
}

void Symmetric (int firstSet[], int secondSet[], int set[]) {
    int k = 0;
    int firstSize = size(firstSet);
    int secondSize = size(secondSet);

    for (int i = 0; i < firstSize; i++) {

        bool isIn = false;
        for (int j = 0; j < secondSize; j++) {
            if (firstSet[i] == secondSet[j]) isIn = true;
        }

        if(!isIn) {
            set[k] = firstSet[i];
            k++;
        }
    }

    for (int i = 0; i < secondSize; i++) {

        bool isIn = false;
        for (int j = 0; j < firstSize; j++) {
            if (secondSet[i] == firstSet[j]) isIn = true;
        }

        if(!isIn) {
            set[k] = secondSet[i];
            k++;
        }
    }

    set[k] = -1;
    //sort(set);
    quickSort(set, 0, size(set) - 1);
}

bool Subset (int setMaly[], int setDuzy[]) {

    if (setMaly[0] == -1) return true;

    int rozmiarMalego = size(setMaly);
    int rozmiarDuzego = size(setDuzy);

    bool result;

    for (int i = 0; i < rozmiarMalego; i++) {

        result = false;

        // musze sprawdzic czy setMaly[i] jest w setDuzy
        bool isIn = false;
        for (int j = 0; j < rozmiarDuzego; j++) {
            if (setMaly[i] == setDuzy[j] ) isIn = true;
        }

        if(isIn) result = true;
        if(!result) break;
    }
    return result;
}

double Arithmetic (int set[]) {

    if (set[0] == -1) return 0;

    double suma = 0., rozmiar = size(set);

    for (int i = 0; i < rozmiar; i++) {
        suma += set[i];
    }

    return suma / rozmiar;
}

double Harmonic (int set[]) {

    if (set[0] == -1) return 1;

    double suma = 0.;
    int rozmiar = size(set);

    for (int i = 0; i < rozmiar; i++) {
        suma += (1. / set[i]);
    }

    return rozmiar / suma;
}

void MinMax(int set[], int *min, int &max) {

    if (set[0] == -1) return;

    *min = set[0];
    max = set[0];

    for (int i = 1; i < size(set); i++) {
        if (*min > set[i]) *min = set[i];
        if (max < set[i]) max = set[i];
    }
}

void Cardinality (int set[], int *power) {
    *power = size(set);
}

void Properties (int set[], char operacje[], double &arytmetyczna, double *harmoniczna, int &min, int *max, int &power) {

    int i = 0;

    while (operacje[i] != 0) {
        if (operacje[i] == 'a') arytmetyczna = Arithmetic(set);
        if (operacje[i] == 'h') *harmoniczna = Harmonic(set);
        if (operacje[i] == 'm') MinMax(set, &min, *max);
        if (operacje[i] == 'c') Cardinality(set, &power);
        i++;
    }
}

//int main () {
//    int set1[] = { 1, 2, 3, 9, 53, 23, 29, -1};
//    int set2[] = { 2, 3, 4, 53, 29,23, -1};
//    int set3[] = {-1};
//    //Add(50, set1);
//
//    int set10[10] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
//
//    int tab[] = {-5, 2, 7, 5, 0, -1};
//    int set[] = {-1, -1, -1, -1, -1, -1};
//
//
//    int set7[] = {1, 2, 3, 4, -1};
//    int set8[] = {3, 4,  -1};
//    int wynik[] = {-1, -1, -1, -1};
//
//    cout << Subset(set3, set8);
//}