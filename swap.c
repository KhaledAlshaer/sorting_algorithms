#include "sort.h"

/**
 *swap - this is the function
 *@f: this is a vraiable
 *@s: this is a vraiable
 *Return: return 0
*/
void swap(int *f , int *s)
{
	int temp = *f;

	*f = *s;
	*s = temp;
}
