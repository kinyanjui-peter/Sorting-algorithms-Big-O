#include "sort.h"

/**
 * swapp - swaps two elements in an array
 * @first: the first element
 * @second: the second element
 */
void swapp(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * lomuto_part - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @first_index: first index of array
 * @second_index: last index of array
 *
 * Description: all values must be accurate
 * Return: new index position
 */
int lomuto_part(int *array, size_t size, int first_index, int second_index)
{
	int pivot = array[second_index], i = first_index, j;

	for (j = first_index; j <= second_index - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swapp(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swapp(&array[i], &array[second_index]);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - implement the quick sort algorithm using recursion
 * @array: the array
 * @size: the size of the array
 * @first_index: first index of the array
 * @second_index: the last index of the array
 * Return: 0
 */
void lomuto_sort(int *array, size_t size, int first_index, int second_index)
{
	int i;

	if (first_index < second_index)
	{
		i = lomuto_part(array, size, first_index, second_index);
		lomuto_sort(array, size, first_index, i - 1);
		lomuto_sort(array, size, i + 1, second_index);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
