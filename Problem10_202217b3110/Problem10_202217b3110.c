#include <stdio.h>

void merge(int array[], int start, int middle, int end) {
    int i, j, k;
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int leftArray[leftSize], rightArray[rightSize];

    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[start + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = { 12, 31, 25, 8, 32, 17, 40, 42 };
    int size = sizeof(array) / sizeof(array[0]);
    printf("Before sorting, array elements are - \n");
    printArray(array, size);
    mergeSort(array, 0, size - 1);
    printf("After sorting, array elements are - \n");
    printArray(array, size);
    return 0;
}
