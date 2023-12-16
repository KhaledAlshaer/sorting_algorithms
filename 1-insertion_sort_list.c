#include "sort.h"


/**
 * swap_nodes- Swaping two node
 * @first: the first node
 * @second: the second node
 * Return: Nothing
*/
void swap_nodes(listint_t *first, listint_t *second)
{
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
}


/**
 * insertion_sort- Algo for the array
 * @arr: the array
 * @size: the size
 * Return: Nothing
*/
void insertion_sort(int *arr, int size)
{
	int i, j, key;

	for (i = 1; i < size; i++)
	{
		j = i - 1;
		key = arr[i];

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


/**
 * insertion_sort_list- Algo for the linked list
 * @list: the linked list
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;

		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_nodes(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list(*list);
			}
			else
				break;
		}

		i = i->next;
	}
}
