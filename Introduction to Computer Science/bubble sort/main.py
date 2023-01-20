from random import *

N = 10


def regularBubbleSort(array, counter):
    n = len(array)
    for i in range(n - 1):
        for j in range(0, n - 1):
            counter = counter + 1
            if array[j] > array[j + 1]:
                counter = counter + 1
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp


def optimizedBubbleSort(array):
    n = len(array)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            # counter incrementation here
            if array[j] > array[j + 1]:
                # counter incrementation here
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp


def insertionSort(array):
    if (n := len(array)) <= 1:
        return
    for i in range(1, n):
        key = array[i]
        j = i - 1
        while j >= 0 and key < array[j]:
            # counter incrementation
            array[j + 1] = array[j]
            # counter incrementation
            j -= 1
        array[j + 1] = key


def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1


def quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)


counter1 = 0
counter2 = 0
counter3 = 0
counter4 = 0
suma1 = 0
suma2 = 0
suma3 = 0
suma4 = 0

for arraySize in range(0, N):
    A = []
    B = []
    for loopCount in range(100):
        for i in range(0, arraySize):
            A[i] = randint(1, arraySize)
            regularBubbleSort(A, counter1)
            suma1 += counter1
            B[loopCount] = counter1
            counter1 = 0

print(A)
print(B)
