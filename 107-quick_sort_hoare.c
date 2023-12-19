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
 * partition- the partitioning function for quick_sort()
 * @arr: the array to sort
 * @size: size of the array
 * @left: the left index
 * @right: the right index
 * Return: move the Pivot to it's right index\
	& the index of the pivot
*/
int partition(int *arr, size_t size, size_t left, size_t right)
{
	int pivot_value = arr[left];
	size_t i = left + 1;
	size_t j = right;

	while (i <= j)
	{
		while (arr[i] < pivot_value)
			i++;

		while (arr[j] > pivot_value)
			j--;

		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}

	swap(&arr[left], &arr[j]);
	print_array(arr, size);
	return (j);
}


/**
 * _quick_sort_hoare- Quick Sort Algo (Hoare Partition Scheme)
 * @arr: the array to sort
 * @size: the size of the array
 * @low: the first index
 * @high: the last index
 * Return: Nothing
*/
void _quick_sort_hoare(int *arr, size_t size, size_t low, size_t high)
{
	size_t pivot_index = 0;

	if (low < high)
	{
		pivot_index = partition(arr, size, low, high);
		_quick_sort_hoare(arr, size, low, pivot_index);
		_quick_sort_hoare(arr, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort_hoare- Quick Sort Algo (Hoare’s Partition Scheme)
 * @array: the array to sort
 * @size: the size of the array
 * Return: Nothing
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort_hoare(array, size, 0, size - 1);
}
