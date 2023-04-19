#include "3-calc.h"

/**
 * main - checking the code for The School students.
 * @thearg: the number of args
 * @theargv: argument vector
 *
 * Return: Always 0.
 */
int main(int thearg, char **theargv)
{
	int (*op_func)(int, int), a, b;

	if (thearg != 4)
		printf("Error\n"), exit(98);

	a = atoi(theargv[1]);
	b = atoi(theargv[3]);

	op_func = get_op_func(theargv[2]);
	if (!op_func)
		printf("Error\n"), exit(99);

	if (!b && (theargv[2][0] == '/' || theargv[2][0] == '%'))
		printf("Error\n"), exit(100);

	printf("%d\n", op_func(a, b));
	return (0);
}
