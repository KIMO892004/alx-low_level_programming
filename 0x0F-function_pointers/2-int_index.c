#include "function_pointers.h"

/**
 * int_index - searches for integer
 * @thearray: the int array
 * @thesize: the array size
 * @thecmp: the compare function
 *
 * Return: the integer index
 */
int int_index(int *thearray, int thesize, int (*thecmp)(int))
{
	int k = 0;

	if (thearray && thesize && thecmp)
		while (k < thesize)
		{
			if (thecmp(thearray[k]))
				return (k);
			k++;
		}
	return (-1);
}
