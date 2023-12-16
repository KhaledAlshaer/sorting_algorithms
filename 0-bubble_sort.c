#include "sort.h"

/**
 * bubble_sort- Bubule Sort Algorithm
 * @array: the array
 * @size: the size of the array
 * Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
