#include "sort.h"

/**
 * swap - 'Swap two integers.'
 * @one: Is the first integer.
 * @two: Is the second integer.
 */

void swap(int *one, int *two)
{
	int aux;

	aux = *one;
	*one = *two;
	*two = aux;
}

/**
 * selection_sort - 'Sorts an array of integers in ascending order
 * using the Selection sort algorithm.'
 * @array: Is an array of integrers.
 * @size: Is the number of integers in the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int aux = 0, pos = 0;

	for (i = 0; i < size; i++)
	{
		aux = array[i];
		for (j = i; j < size; j++)
		{
			if (aux > array[j])
			{
				aux = array[j];
				pos = j;
			}
		}
		if (aux != array[i])
		{
			swap(&array[i], &array[pos]);
			print_array(array, size);
		}
	}
}
