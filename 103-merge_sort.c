#include "sort.h"

/**
 * merge- merging after the recursion\
 * Disclamer: this implementation doesnot meet the ALX requitmentsb\
 * but it do the trick
 * @array: the original array
 * @size: the size of it
 * @left: index of the left array
 * @right: index of the last element
 * @mid: index of the mid element
 * Return: Nothing
*/
void merge(int *array, size_t size, size_t left, size_t right, size_t mid)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left;
	int *new_array = malloc(sizeof(int) * (size - 1));

	if (!new_array)
		return;

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
		{
			new_array[k] = array[i];
			i++, k++;
		}
		else
		{
			new_array[k] = array[j];
			j++, k++;
		}
	}

	while (i <= mid)
	{
		new_array[k] = array[i];
		i++, k++;
	}

	while (j <= right)
	{
		new_array[k] = array[j];
		j++, k++;
	}

	for (i = left; i < k; i++)
		array[i] = new_array[i];
	free(new_array);
}


/**
 * _merge_sort- the merge helper
 * @array: the original array
 * @size: the size of it
 * @low: index of the first element
 * @high: index of the last element
 * Return: Nothing
*/
void _merge_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		_merge_sort(array, size, low, mid);
		_merge_sort(array, size, mid + 1, high);
		merge(array, size, low, high, mid);
	}
}

/**
 * merge_sort- the merge func
 * @array: the original array
 * @size: the size of it
 * Return: Nothing
*/
void merge_sort(int *array, size_t size)
{
	if (size < 1 || !array)
		return;

	_merge_sort(array, size, 0, size - 1);
}
