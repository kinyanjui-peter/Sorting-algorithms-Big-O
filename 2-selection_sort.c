#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * 		    order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: print the array after each time you swap two elements 
 */
void selection_sort(int *array, size_t size){
	size_t outer, min = 0, next;
	size_t temp;

	if(array == NULL || size < 2){
		return;
	}
	
	for(outer = 0; outer <= size - 1; outer++){
		min = outer;
		for(next = outer + 1; next < size; next++){
			if(array[next] < array[min]){
				min = next;
			}
		}
		if(array[min] != array[outer]){
			temp = array[outer];
			array[outer] = array[min];
			array[min] = temp;
			myprint(array, size);
		}
	}
}
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void myprint(const int *array, size_t size)
{
        size_t i;

        i = 0;

        while (array && i < size)
        {
                if (i > 0)
                        printf(", ");
                printf("%d", array[i]);
                ++i;
        }
        printf("\n");
}
