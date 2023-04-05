#include "main.h"

/**
 * _puts_recursion - prints a sting, followed by a new line
 * @s: pointer to the string
 * Return: void
 */

void _puts_recursion(char *s)
{
	if (*s == '\n')
	{
		_putchar('\n');
	}
	else
	{
		_putschar(*s);
		_put_recursion(s + 1);
	}
}
