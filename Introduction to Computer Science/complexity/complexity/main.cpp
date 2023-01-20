#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>

#define N 500

using namespace std;

void badBubbleSort(int A[], int n, int &counter) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counter++; // counts comparisons
            if (A[j] > A[j + 1]) { // if current element is bigger than next
                counter++; // counts swaps
                swap(A[j], A[j + 1]); // swaps element with its consequent
            }
        }
    }
}

void bubbleSort(int A[], int n, int &counter) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i); j++) { // no need to check the end of the array, as it is already sorted
            counter++; // counts comparisons
            if (A[j] > A[j + 1]) { // if current element is bigger than next
                counter++; // counts swaps
                swap(A[j], A[j + 1]); // swaps element with its consequent
            }
        }
    }
}

void insertionSort(int A[], int n, int &counter) {
    int key, i, j;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            counter++; // counts comparisons
            A[i+1] = A[i];
            counter++; // counts swaps
            i--;
        }
        A[i + 1] = key;
    }
}

int partition( int arr[], int start, int end, int &counter) {
    int pivot = arr[start];
    int count = 0;
    for (int i = (start + 1); i <= end; i++) {
        if (arr[i] <= pivot) {
            counter++;
            count++;
        }
    }
    int pivotIndex = start + count;
    counter++; // counts swaps
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            counter++; // counts swaps;
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int A[], int start, int end, int &counter) {
    if (start >= end)
        return;
    int p = partition(A, start, end, counter);
    quickSort(A, start, p - 1, counter);
    quickSort(A, p + 1, end, counter);
}

bool isPrimeSqrt(int n, int &counter) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        counter++;
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPrimeHalf(int n, int &counter) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= n/2; i++) {
        counter++;
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPrimeWhole(int n, int &counter) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= n; i++) {
        counter++;
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {

    srand(time(nullptr));

    fstream resultsBadBubbleSort;
    fstream resultsBubbleSort;
    fstream resultsInsertionSort;
    fstream resultsQuickSort;
    fstream resultsPrimeSqrt;
    fstream resultsPrimeHalf;
    fstream resultsPrimeWhole;

    resultsBadBubbleSort.open("resultsBadBubbleSort.txt", ios::out);
    resultsBubbleSort.open("resultsBubbleSort.txt", ios::out);
    resultsInsertionSort.open("resultsInsertionSort.txt", ios::out);
    resultsQuickSort.open("resultsQuickSort.txt", ios::out);
    resultsPrimeSqrt.open("resultsPrimeSqrt.txt", ios::out);
    resultsPrimeHalf.open("resultsPrimeHalf.txt", ios::out);
    resultsPrimeWhole.open("resultsPrimeWhole.txt", ios::out);

    int counterBadBubbleSort = 0;
    int counterBubbleSort = 0;
    int counterInsertionSort = 0;
    int counterQuickSort = 0;
    int counterPrimeSqrt = 0;
    int counterPrimeHalf = 0;
    int counterPrimeWhole = 0;

    int sumBadBubbleSort = 0;
    int sumBubbleSort = 0;
    int sumInsertionSort = 0;
    int sumQuickSort = 0;

    for (int arraySize = 1; arraySize <= N; arraySize++) {

        // counting results for not optimized bubble sort
        int AarrayBadBubbleSort[arraySize];
        int BarrayBadBubbleSort[100]; // array to store counter values
        for (int & loops : BarrayBadBubbleSort) {
            for (int i = 0; i < arraySize; i++) {
                AarrayBadBubbleSort[i] = rand() % arraySize;
            }
            badBubbleSort(AarrayBadBubbleSort, arraySize, counterBadBubbleSort);
            sumBadBubbleSort += counterBadBubbleSort;
            loops = counterBadBubbleSort;
            counterBadBubbleSort = 0;
        }
        resultsBadBubbleSort << arraySize << " " << (sumBadBubbleSort/100) << endl;
        sumBadBubbleSort = 0;

        // counting results for optimized bubble sort
        int AarrayBubbleSort[arraySize];
        int BarrayBubbleSort[100]; // array to store counter values
        for (int & loops : BarrayBubbleSort) {
            for (int i = 0; i < arraySize; i++) {
                AarrayBubbleSort[i] = rand() % arraySize;
            }
            bubbleSort(AarrayBubbleSort, arraySize, counterBubbleSort);
            sumBubbleSort += counterBubbleSort;
            loops = counterBubbleSort;
            counterBubbleSort = 0;
        }
        resultsBubbleSort << arraySize << " " << (sumBubbleSort/100) << endl;
        sumBubbleSort = 0;

        // counting results for insertion sort
        int AarrayInsertionSort[arraySize];
        int BarrayInsertionSort[100]; // array to store counter values
        for (int & loops : BarrayInsertionSort) {
            for (int i = 0; i < arraySize; i++) {
                AarrayInsertionSort[i] = rand() % arraySize;
            }
            insertionSort(AarrayInsertionSort, arraySize, counterInsertionSort);
            sumInsertionSort += counterInsertionSort;
            loops = counterInsertionSort;
            counterInsertionSort = 0;
        }
        resultsInsertionSort << arraySize << " " << (sumInsertionSort/100) << endl;
        sumInsertionSort = 0;

        // counting results for quick sort
        int AarrayQuickSort[arraySize];
        int BarrayQuickSort[100]; // array to store counter values
        for (int & loops : BarrayQuickSort) {
            for (int i = 0; i < arraySize; i++) {
                AarrayQuickSort[i] = rand() %arraySize;
            }
            quickSort(AarrayQuickSort, 0, arraySize, counterQuickSort);
            sumQuickSort += counterQuickSort;
            loops = counterQuickSort;
            counterQuickSort = 0;
        }
        resultsQuickSort << arraySize << " " << (sumQuickSort/100) << endl;
        sumQuickSort = 0;
    }

    for (int i = 0; i < 100000; i++){

        int counterTmp = 0;
        counterPrimeSqrt = 0;
        counterPrimeHalf = 0;
        counterPrimeWhole = 0;


        isPrimeSqrt(i, counterPrimeSqrt);
        isPrimeHalf(i, counterPrimeHalf);
        isPrimeWhole(i, counterPrimeWhole);

        if(isPrimeSqrt(i, counterTmp)) {
            resultsPrimeSqrt << i << " " << counterPrimeSqrt << std::endl;
            resultsPrimeHalf << i << " " << counterPrimeHalf << std::endl;
            resultsPrimeWhole << i << " " << counterPrimeWhole << std::endl;
        }



        counterPrimeSqrt = 0;
        counterPrimeHalf = 0;
        counterPrimeWhole = 0;
    }

    resultsBadBubbleSort.close();
    resultsBubbleSort.close();
    resultsInsertionSort.close();
    resultsQuickSort.close();
    resultsPrimeSqrt.close();
    resultsPrimeHalf.close();
    resultsPrimeWhole.close();
    return 0;
}
