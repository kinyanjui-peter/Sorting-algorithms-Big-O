#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"

void swap_next(listint_t **list, listint_t **end, listint_t **ptr_to_swapp);
void swap_prev(listint_t **list, listint_t **end, listint_t **ptr_to_swapp);
void cocktail_sort_list(listint_t **list);

/**
 * swap_next - Swap a node in a listint_t doubly-linked list
 *             with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the end of the doubly-linked list.
 * @ptr_to_swapp: A pointer to the current swapping node.
 */
void swap_next(listint_t **list, listint_t **end, listint_t **ptr_to_swapp)
{
    listint_t *temp = (*ptr_to_swapp)->next;

    if ((*ptr_to_swapp)->prev != NULL)
        (*ptr_to_swapp)->prev->next = temp;
    else
        *list = temp;
    temp->prev = (*ptr_to_swapp)->prev;
    (*ptr_to_swapp)->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = *ptr_to_swapp;
    else
        *end = *ptr_to_swapp;
    (*ptr_to_swapp)->prev = temp;
    temp->next = *ptr_to_swapp;
    *ptr_to_swapp = temp;
}

/**
 * swap_prev - Swap a node in a listint_t doubly-linked
 *             list with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @end: A pointer to the end of the doubly-linked list.
 * @ptr_to_swapp: A pointer to the current swapping node.
 */
void swap_prev(listint_t **list, listint_t **end, listint_t **ptr_to_swapp)
{
    listint_t *temp = (*ptr_to_swapp)->prev;

    if ((*ptr_to_swapp)->next != NULL)
        (*ptr_to_swapp)->next->prev = temp;
    else
        *end = temp;
    temp->next = (*ptr_to_swapp)->next;
    (*ptr_to_swapp)->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = *ptr_to_swapp;
    else
        *list = *ptr_to_swapp;
    (*ptr_to_swapp)->next = temp;
    temp->prev = *ptr_to_swapp;
    *ptr_to_swapp = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *end, *ptr_to_swapp;
    bool shaken_not_stirred = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (end = *list; end->next != NULL;)
        end = end->next;

    while (shaken_not_stirred == false)
    {
        shaken_not_stirred = true;
        for (ptr_to_swapp = *list; ptr_to_swapp != end; \
			ptr_to_swapp = ptr_to_swapp->next)
        {
            if (ptr_to_swapp->n > ptr_to_swapp->next->n)
            {
                swap_next(list, &end, &ptr_to_swapp);
                print_list((const listint_t *)*list);
                shaken_not_stirred = false;
            }
        }
        for (ptr_to_swapp = ptr_to_swapp->prev; ptr_to_swapp != *list; \
			ptr_to_swapp = ptr_to_swapp->prev)
        {
            if (ptr_to_swapp->n < ptr_to_swapp->prev->n)
            {
                swap_prev(list, &end, &ptr_to_swapp);
                print_list((const listint_t *)*list);
                shaken_not_stirred = false;
            }
        }
    }
}
