#include <stdio.h>

void insertionSort(int array[], int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && temp < array[j]) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 12, 31, 25, 8, 32, 17 };
    int size = sizeof(array) / sizeof(array[0]);
    printf("Before sorting array elements are - \n");
    printArray(array, size);
    insertionSort(array, size);
    printf("After sorting array elements are - \n");
    printArray(array, size);
    return 0;
}
