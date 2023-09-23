#include "sort.h"

/**
 * swap - for swapping 
 * @a: item1
 * @b: item2
 * return - switched item
 *
 */
void swap(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
    	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * 			using the Bubble sort algorithm
 * @array: contain numbers to be swapped
 * Return - print the array after each time you swap two elements
 */
void bubble_sort(int *array, size_t size)
{
	/*declaration and initialization*/
	size_t x, y;
	int swapped;
	
	if (array == NULL || size < 2)
		return;

	for(x = 0; x < size - 1; x++)
        {
                swapped = 0; /*check if any swapp was made*/
                for(y = 0; y < size - x - 1; y++)
                {
                        if(array[y] > array[y + 1])
                        {
                                swap(&array[y], &array[y + 1]);
                                swapped = 1;
				myprint(array, size);
                        }
                }
                 	
                if(swapped == 0)
                        break;
        }
	return;
}
