#include <stdio.h>

void selection_sort(int array[], int size) {
    int i, j, smallest_index, temp;

    for (i = 0; i < size - 1; i++) {
        smallest_index = i;

        for (j = i + 1; j < size; j++) {
            if (array[j] < array[smallest_index]) {
                smallest_index = j;
            }
        }

        temp = array[smallest_index];
        array[smallest_index] = array[i];
        array[i] = temp;
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
