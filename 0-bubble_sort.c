#include "sort.h"

/**
 * - this is the function
 *@: this is a vraiable
 *Return: return 0
*/
void bubble_sort(int *array, size_t size)
{
	int i, j;

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
				swap(array[j], array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
