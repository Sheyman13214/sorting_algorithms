#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Function that sorts a doubly linked list using the
 * insertion sort algorithm.
 * It iterates through the elements, comparing each with the previous one.
 * If an element is smaller, it swaps them.
 * @list: Head node of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	/* Check if the list is empty or contains only one element */
	if (!(*list) || !(*list)->next)
		return;

	/* Initialize current and next_node pointers */
	current = (*list)->next;
	next_node = current;

	while (current) /* Iterate through the list */
	{
		/* Save the next node for the next iteration */
		next_node = current->next;
		/* Perform insertion sort by comparing with previous nodes */
		while (current->prev && current->n < current->prev->n)
		{
			/* Swap adjacent nodes */
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			/* Update node positions */
			current->next = current->prev;
			if (current->next)
			{
				current->prev = current->next->prev;
				current->next->prev = current;
			}
			/* Update the head of the list if needed */
			if (current->prev)
				current->prev->next = current;
			else
				(*list) = current;

			print_list(*list); /* Print the current state of the list */
		}
		current = next_node; /* Move to the next node in the iteration */
	}
}
