#include "sort.h"

void first_half_array(int *first_half, int *buffer, size_t start, size_t center,
                      size_t back);
void recursive_merge_sort(int *first_half, int *buffer, size_t start, size_t back);
void merge_sort(int *array, size_t size);

/**
 * first_half_array - Sort the first half of an array of integers.
 * @first_half: A subarray representing the first half of the array to sort.
 * @buffer: A buffer to store the sorted first half.
 * @start: The start index of the array.
 * @center: The center index of the array.
 * @back: The back index of the array.
 */
void first_half_array(int *first_half, int *buffer, size_t start, size_t center,
                     size_t back)
{
    size_t index_i, count_j, index_k = 0;

    printf("Merging...\n[left]: ");
    print_array(first_half + start, center - start);

    printf("[right]: ");
    print_array(first_half + center, back - center);

    for (index_i = start, count_j = center; index_i < center && count_j < back; index_k++)
        buffer[index_k] = (first_half[index_i] < first_half[count_j]) ? first_half[index_i++] : first_half[count_j++];
    for (; index_i < center; index_i++)
        buffer[index_k++] = first_half[index_i];
    for (; count_j < back; count_j++)
        buffer[index_k++] = first_half[count_j];
    for (index_i = start, index_k = 0; index_i < back; index_i++)
        first_half[index_i] = buffer[index_k++];

    printf("[Done]: ");
    print_array(first_half + start, back - start);
}

/**
 * recursive_merge_sort - Implement the merge sort algorithm through recursion.
 * @first_half: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @start: The start index of the subarray.
 * @back: The back index of the subarray.
 */
void recursive_merge_sort(int *first_half, int *buffer, size_t start, size_t back)
{
    size_t center;

    if (back - start > 1)
    {
        center = start + (back - start) / 2;
        recursive_merge_sort(first_half, buffer, start, center);
        recursive_merge_sort(first_half, buffer, center, back);
        first_half_array(first_half, buffer, start, center, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    recursive_merge_sort(array, buffer, 0, size);

    free(buffer);
}
