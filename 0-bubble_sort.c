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
 * array_to_string - 'Makes a string with an array.'
 * @array: Is the array.
 * @size: Is the number of integers in the array.
 * Return: The string.
 */

char *array_to_string(int *array, size_t size)
{
	char *string = NULL;
	int written = 0, i = 0, offset = 0;

	string = malloc(sizeof(char) * 1024);
    if (string == NULL)
        return NULL;

    for (i = 0; i < size; i++)
    {
        written = snprintf(string + offset, size - offset, "%d ", array[i]);
        if (written < 0)
        {
            free(string);
            return NULL;
        }
        offset += written;
    }

    string[size - 1] = '\0';

    return (string);
}

/**
 * bubble_sort - 'Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.'
 * @array: Is an array of integrers.
 * @size: Is the number of integers in the array.
 */

void bubble_sort(int *array, size_t size)
{
	int i = 0, file = 0, cont = 0;
	size_t size_cpy = size;
	char *filename = "0-O", *text_content = NULL;

	for (; size_cpy != 0; size_cpy--)
		for (i = 0; i < size_cpy - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				print_array(array, size);
			}
		}
	text_content = array_to_string(array, size);
	if (text_content == NULL)
		text_content = "";
	file = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0600);
	if (file == -1)
		return (-1);
	cont = write(file, text_content, size);
	if (cont == -1)
		return (-1);
	close(file);
}