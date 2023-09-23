#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, size_t size) {
    int swapped;
    size_t j, i, k;

    for(i = 0; i < size - 1; i++) {
        swapped = 0;
        for(j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }

        printf("Pass %lu: ", i + 1);
        for(k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");

       
        if (swapped == 0) {
            break;
        }
    }
}
