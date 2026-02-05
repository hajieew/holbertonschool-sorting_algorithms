#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		key = current;
		current = current->next;

		while (key->prev && key->n < key->prev->n)
		{
			listint_t *prev = key->prev;
			listint_t *next = key->next;

			prev->next = next;
			if (next)
				next->prev = prev;

			key->prev = prev->prev;
			key->next = prev;

			if (prev->prev)
				prev->prev->next = key;
			else
				*list = key;

			prev->prev = key;

			print_list(*list);
		}
	}
}
