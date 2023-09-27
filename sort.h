#ifndef SORT_H
#define SORT_H

/*HEADER FILES*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*DATA STRUCTURES*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/*FUNCTION PROTOTYPE*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void myprint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
void swapp(int *first, int *second);
int lomuto_part(int *array, size_t size, int first_index, int second_index);
void lomuto_sort(int *array, size_t size, int first_index, int second_index);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_next(listint_t **list, listint_t **end, listint_t **ptr_to_swapp);
void swap_prev(listint_t **list, listint_t **end, listint_t **ptr_to_swapp);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void first_half_array(int *first_half, int *buffer, size_t start, size_t center,
                      size_t back);
void recursive_merge_sort(int *first_half, int *buffer, size_t start, size_t back);
#endif /*end of the sort header file*/

