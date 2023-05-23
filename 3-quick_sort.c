#include "sort.h"
/**
 * swap - swap
 *
 * @i: i.
 * @j: j.
 * @size: size.
 * @array: array.
 */
void swap(int *i, int *j, size_t size, int *array)
{
	int tmp = 0;

	if (*i != *j)
	{
	tmp = *i;
	*i = *j;
	*j = tmp;
	print_array(array, size);
	}
}
/**
 * partition - partition.
 *
 * @array: array.
 * @l: l.
 * @r: r.
 * @size: size.
 *
 * Return: returns the "pivot".
 */
int partition(int *array, int l, int r, size_t size)
{
	int pivot = array[r];
	int i = l, j = l;

	for (j = l; j < r; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j], size, array);
			i++;
		}
	}
	swap(&array[i], &array[r], size, array);
	return (i);
}
/**
 * quick_sort_Rec - quick sort.
 *
 * @array: array.
 * @low: low.
 * @high: high.
 * @size: size.
 */
void quick_sort_Rec(int *array, int low, int high, size_t size)
{
	int i = 0;

	if (low < high)
	{
		i = partition(array, low, high, size);
		quick_sort_Rec(array, low, i - 1, size);
		quick_sort_Rec(array, i + 1, high, size);
	}
}
/**
 * quick_sort - quick sort.
 *
 * @array: array.
 * @size: size.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_Rec(array, 0, size - 1, size);
}