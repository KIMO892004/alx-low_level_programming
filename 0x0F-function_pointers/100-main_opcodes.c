#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - check the code for The School students.
 * @arg: the number of args
 * @thearg: argument vector
 *
 * Return: Always 0.
 */
int main(int arg, char **thearg)
{
	char *p = (char *)main;
	int b;

	if (arg != 2)
		printf("Error\n"), exit(1);
	b = atoi(thearg[1]);
	if (b < 0)
		printf("Error\n"), exit(2);

	while (b--)
		printf("%02hhx%s", *p++, b ? " " : "\n");
	return (0);
}
