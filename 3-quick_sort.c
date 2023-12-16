#include "sort.h"


/**
 * lumoto- the partitioning function for quick_sort()
 * @left: the left index
 * @right: the right index
 * Rerurn: the index of the pivot
*/
int lumoto(int *arr, int size, int left, int right)
{
    int pivot_val = arr[right];
    int i = left - 1;
    int j;

    for(j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot_val)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[right]);
    print_array(arr, size);
    return (i+1);
}


/**
 * quick_sort- Quick Sort Algo (Lomuto’s Partition Scheme)
 * @array: the array to sort
 * @left: the first index
 * @right: the last index
 * Return: Nothing
*/
void quick_sort_helper(int *arr, int size, int left, int right)
{
    if (left < right)
    {
        int pivot_idx = lumoto(arr, size, left, right);
        quick_sort_helper(arr, size, left, pivot_idx - 1);
        quick_sort_helper(arr, size, pivot_idx + 1, right);
    }
}


/**
 * quick_sort- Quick Sort Algo (Lomuto’s Partition Scheme)
 * @array: the array to sort
 * @size: the size of the array
 * Return: Nothing
void quick_sort(int *array, size_t size)
{
    int left = 0;
    int right = size - 1;
    if (!array || size < 2)
        return;
    quick_sort_helper(array, size,left, right);
}
*/

void quick_sort(int *array, size_t size) {
    int pivot;
    size_t i, j;

    if (!array || size < 2)
        return;

        pivot = array[size - 1];
        i = 0; 
    for (j = 0; j < size - 1; j++) {
        if (array[j] <= pivot) {
        swap(&array[i], &array[j]); 
            i++;
        }
    }

    swap(&array[i], &array[size - 1]); 

    quick_sort(array, i); 
    quick_sort(&array[i + 1], size - i - 1);
}
