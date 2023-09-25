#include "sort.h"

/**
 * get_max_number - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max_number(int *array, int size)
{
	int max, index;

	for (max = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	return (max);
}

/**
 * sort_count - Sort an array of integers in ascending order
 *              using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_list, max, i;

	if (array == NULL || size < 2)
		return;

	sorted_list = malloc(sizeof(int) * size);
	if (sorted_list == NULL)
		return;
	max = get_max_number(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted_list);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_list[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_list[i];

	free(sorted_list);
	free(count);
}
