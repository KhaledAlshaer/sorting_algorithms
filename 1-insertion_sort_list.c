#include "sort.h"

void insertion_sort(int *arr, int size)
{
    int i, j, key;

    for (i = 1; i < size; i++)
    {
        j = i - 1;
        key = arr[i];

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertion_sort_list(listint_t **list)
{
    
}
