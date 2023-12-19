#include "sort.h"

/**
 *swap - this is the function
 *@f: this is a vraiable
 *@s: this is a vraiable
 *Return: return 0
*/
void swap_nodes(listint_t *f, listint_t *s)
{
	if (f && s)
	{
		if (f->prev)
		{
			f->prev->next = s;
		}
		if (s->next)
		{
			s->next->prev = f;
		}

		if (f->next != s)
		{
			f->next = s->next;
			s->prev = f->prev;
			s->next = f;
			f->prev = s;
		}
		else
		{
			f->next = s;
			s->prev = f;
			s->next = f->next;
			f->prev = s->prev;
		}
	}	
}

/**
 *insertion_sort_list - this is the function
 *@list: this is a vraiable
 *Return: return 0
*/
void insertion_sort_list(listint_t **list)
{
	int i = 1, j, key;

	if (*list && (*list)[i].next)
	{
		key = (*list)[i].n;
		j = i-1;

		while ((*list)[i].n)
		{
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




/**
 * void insertion_sort_list(listint_t **list)
{
	int j, key;
	listint_t *current;

	if (list && *list)
	{
		current = (*list)->next;

		while (current)
		{
			key = current->n;
			j = current->prev ? current->prev->n : 0;

			while (j >= 0 && (*list)[j + 1].n > key)
			{
				swap_nodes(&(*list)[j], current);
				print_list(*list);
				j--;
			}
			
			current = current->next;
		}
	}
}
*/

