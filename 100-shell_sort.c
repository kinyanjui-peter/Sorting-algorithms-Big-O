#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_ints(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
/**
 * print_array - Prints an array of integers
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

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, count, nav;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (count = gap; count < size; count++)
		{
			nav = count;
			while (nav >= gap && array[nav - gap] > array[nav])
			{
				swap_ints(array + nav, array + (nav - gap));
				nav -= gap;
			}
		}
		myprint(array, size);
	}
}
