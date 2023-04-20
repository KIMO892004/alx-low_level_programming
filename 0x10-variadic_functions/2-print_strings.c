#include "variadic_functions.h"


/**
 * print_strings - printing the strings with separator
 * @separatorr: the string separator
 * @k: the number of arguments
 * @....: the strings to print
 *
 * Return: void
 */
void print_strings(const char *separatorr, const unsigned int k, ...)
{
	int i = k;
	char *str;
	va_list ap;

	if (!k)
	{
		printf("\n");
		return;
	}
	va_start(ap, k);
	while (i--)
		printf("%s%s", (str = va_arg(ap, char *)) ? str : "(nil)",
			i ? (separatorr ? separatorr : "") : "\n");
	va_end(ap);
}
