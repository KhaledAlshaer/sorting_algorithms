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
	int j, key;
	listint_t *current;

	if (list && *list)
	{
		current = (*list)->next;

		while (current)
		{
			key = current->n;
			j = current->prev ? current->prev->n : 0;

			while (j >= 0 && (*list)[j].n > key)
			{
				swap_nodes(&(*list)[j], current);
				print_list(*list);
				j--;
			}
			
			current = current->next;
		}
	}
}
