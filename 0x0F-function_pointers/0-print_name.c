#include "function_pointers.h"

/**
 * print_name - prints a name
 * @thename: the string name
 * @k: the printing function pointer
 *
 * Return: void
 */
void print_name(char *thename, void (*k)(char *))
{
	if (thename && k)
		k(thename);
}
