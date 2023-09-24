#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double linked list
 * Return - sorted list after every sort
 */

void insertion_sort_list(listint_t **list){
	listint_t *temp, *prev_prev, *current, *current_next;

	if (list == NULL)
		return;

	temp = *list;

	while (temp){
		if (temp->prev && temp->prev->n > temp->n){
			/* Store the necessary pointers for swapping */
			prev_prev = temp->prev->prev;
			current = temp->prev;
			current_next = temp;
			
			/* Adjust the pointers to swap the nodes */
			current->next = current_next->next;

			if (current_next->next)
				current_next->next->prev = current;

			current_next->prev = prev_prev;
			current_next->next = current;

			if (prev_prev)
				prev_prev->next = current_next;
			else
				*list = current_next;

			current->prev = current_next;
			temp = *list;
			print_list(*list);
			continue; /* Continue to the next iteration */
		}
		else
			temp = temp->next;
	}
}
