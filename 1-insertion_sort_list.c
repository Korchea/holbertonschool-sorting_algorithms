#include "sort.h"

/**
 * swap - 'Swap two integers.'
 * @one: Is the first integer.
 * @two: Is the second integer.
 */

void swap(listint_t **list, listint_t **head)
{
	listint_t *aux = (*list)->prev;

	if (aux->prev != NULL)
	{
		aux->next = (*list)->next;
		aux->prev->next = (*list);
		if ((*list)->next != NULL)
			(*list)->next->prev = aux;
		(*list)->next = aux;
		(*list)->prev = aux->prev;
		aux->prev = (*list);
	}
	else
	{
		aux->next = (*list)->next;
		if ((*list)->next != NULL)
			(*list)->next->prev = aux;
		(*list)->next = aux;
		(*list)->prev = aux->prev;
		aux->prev = (*list);
		(*head) = (*list);
	}
}

/**
 * insertion_sort_list - 'Sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.'
 * @list: Is the list of integrers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = (*list);

	while (aux->next != NULL)
	{
		aux = aux->next;
		while (aux->prev != NULL && aux->n < aux->prev->n)
		{
			swap(&aux, &(*list));
			print_list((*list));
		}
	}
}
