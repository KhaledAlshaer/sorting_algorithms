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
 * lumoto- the partitioning function for quick_sort()
 * @arr: the array to sort
 * @size: size of the array
 * @left: the left index
 * @right: the right index
 * Return: move the Pivot to it's right index\
	& the index of the pivot
*/
int lumoto(int *arr, int size, int left, int right)
{
	int pivot_val = arr[right];
	int i = left, j = left;

	for (; j < right; j++)
	{
		if (arr[j] <= pivot_val)
		{
			if (arr[i] != arr[j])
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}

	if (arr[i] != arr[right])
	{
		swap(&arr[i], &arr[right]);
		print_array(arr, size);
	}
	return (i);
}


/**
 * quick_sort_helper- Quick Sort Algo (Lomuto’s Partition Scheme)
 * @arr: the array to sort
 * @size: the size of the array
 * @low: the first index
 * @high: the last index
 * Return: Nothing
*/
void quick_sort_helper(int *arr, int size, int low, int high)
{
	if (low < high)
	{
		int pivot_idx = lumoto(arr, size, low, high);

		quick_sort_helper(arr, size, low, pivot_idx - 1);
		quick_sort_helper(arr, size, pivot_idx + 1, high);
	}
}


/**
 * quick_sort- Quick Sort Algo (Lomuto’s Partition Scheme)
 * @array: the array to sort
 * @size: the size of the array
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	quick_sort_helper(array, size, 0, size - 1);
}
