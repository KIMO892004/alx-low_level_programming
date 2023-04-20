#include "variadic_functions.h"


/**
 * print_numbers - printing the numbers with separator
 * @separatorr: the string separator
 * @k: the number of arguments
 * @....: the integers to print
 *
 * Return: void
 */
void print_numbers(const char *separatorr, const unsigned int k, ...)
{
	int i = k;
	va_list ap;

	if (!k)
	{
		printf("\n");
		return;
	}
	va_start(ap, k);
	while (i--)
		printf("%d%s", va_arg(ap, int),
			i ? (separatorr ? separatorr : "") : "\n");
	va_end(ap);
}
