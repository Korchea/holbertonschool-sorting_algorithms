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
 * bubble_sort - 'Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.'
 * @array: Is an array of integrers.
 * @size: Is the number of integers in the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t size_cpy = size, i = 0;

	for (; size_cpy != 0; size_cpy--)
		for (i = 0; i < size_cpy - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				print_array(array, size);
			}
		}
}
