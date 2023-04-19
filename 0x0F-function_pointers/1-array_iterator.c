#include "function_pointers.h"

/**
 * array_iterator - maps an array through a function pointer
 * @thearray: the int array
 * @thesize: the array size
 * @theaction: function pointer
 *
 * Return: void
 */
void array_iterator(int *thearray, size_t thesize, void (*theaction)(int))
{
	int *theend = thearray + thesize - 1;

	if (thearray && thesize && theaction)
		while (thearray <= theend)
			theaction(*thearray++);
}
