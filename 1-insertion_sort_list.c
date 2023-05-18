#include "sort.h"

/**
 * swap - 'Swap two integers.'
 * @one: Is the first integer.
 * @two: Is the second integer.
 */

void swap(listint_t **list)
{
	listint_t *aux = (*list)->prev;

	aux->next = (*list)->next;
	if (aux->prev != NULL)
	{
		aux->prev->next = (*list);
		(*list)->prev = aux->prev;
	}
			printf("Estoy parado en %d\n", (*list)->n);
	(*list)->next->prev = aux;
	(*list)->next = aux;
	aux->prev = (*list);
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
			swap(&aux);
			print_list((*list));
		}
	}
}
