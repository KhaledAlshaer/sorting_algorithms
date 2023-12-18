#include "sort.h"

/**
 *swap - this is the function
 *@f: this is a vraiable
 *@s: this is a vraiable
 *Return: return 0
*/
void swap_nodes(listint_t *f, listint_t *s)
{
	if (f)
	{
		f->prev->next = s;
	}

	if (s)
	{
		s->next->prev = f;
	}
	if (f && s)
	{
		f->next = s->next;
		s->prev = f->prev;
		s->next = f;
		f->prev = s;
	}
}

/**
 *insertion_sort_list - this is the function
 *@list: this is a vraiable
 *Return: return 0
*/
void insertion_sort_list(listint_t **list)
{
	int i = 1, j;
	int key;

	if (list)
	{
		while (i)
		{
			key = (*list)[i].n;
			j = i - 1;

			while (j >= 0 && (*list)[j].n > key)
			{
				swap_nodes(&(*list)[j], &(*list)[j + 1]);
				print_list(*list);
				j--;
			}
			i++;
		}
	}
}
