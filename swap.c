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
