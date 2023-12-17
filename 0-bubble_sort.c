#include "sort.h"

/**
 *bubble_sort - this is the function
 *@array: this is a vraiable
 *@size: this is a vraiable
 *Return: return 0
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
