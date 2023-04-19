#include "3-calc.h"

/**
* get_op_func - returning the pointer to right op function
* @k: string operator
*
* Return: the right function pointer
*/
int (*get_op_func(char *k))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int r = 0;

	while (r < 5)
	{
		if (k && k[0] == ops[r].op[0] && !k[1])
			return (ops[r].f);
		r++;
	}

	return (NULL);
}
