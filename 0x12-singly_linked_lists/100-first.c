#include "lists.h"

void _constructor(void) __attribute__ ((constructorr));

/**
 * _constructor - executing before main()
 *
 * Return: void
 */
void _constructor(void)
{
	printf("You are beat!! and yet, you must allow,\n"
		"I bore my house upon my back!!\n");
}
