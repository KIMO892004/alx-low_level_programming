#include "variadic_functions.h"


/**
 * sum_them_all - sums variable arguments that we use
 * @k: the number of arguments
 * @....: the integers to sum
 *
 * Return: the integer sum
 */
int sum_them_all(const unsigned int k, ...)
{
	int s = 0, i = k;
	va_list ap;

	if (!k)
		return (0);
	va_start(ap, k);
	while (i--)
		s += va_arg(ap, int);
	va_end(ap);
	return (s);
}
