#include "sort.h"


/**
 * swap- Swaping two int
 * @first: the first int
 * @second: the second int
 * Return: Nothing
*/
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * bubble_sort- Bubule Sort Algorithm
 * @array: the array
 * @size: the size of the array
 * Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j + 1] && array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
