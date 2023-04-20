#include "variadic_functions.h"

/**
 * format_char - formats of the character
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_char(char *separatorr, va_list app)
{
	printf("%s%c", separatorr, va_arg(app, int));
}

/**
 * format_int - formats of the integer
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_int(char *separatorr, va_list app)
{
	printf("%s%d", separatorr, va_arg(app, int));
}

/**
 * format_float - formats of the float
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_float(char *separatorr, va_list app)
{
	printf("%s%f", separatorr, va_arg(app, double));
}

/**
 * format_string - formats of the string
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_string(char *separatorr, va_list app)
{
	char *str = va_arg(app, char *);

	switch ((int)(!str))
		case 1:
			str = "(nil)";

	printf("%s%s", separatorr, str);
}

/**
 * print_all - prints anything
 * @format: the format of the string
 */
void print_all(const char * const format, ...)
{
	int i = 0, j;
	char *separatorr = "";
	va_list app;
	token_t tokens[] = {
		{"c", format_char},
		{"i", format_int},
		{"f", format_float},
		{"s", format_string},
		{NULL, NULL}
	};

	va_start(app, formatt);
	while (format && format[i])
	{
		j = 0;
		while (tokens[j].token)
		{
			if (format[i] == tokens[j].token[0])
			{
				tokens[j].f(separatorr, app);
				separatorr = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(app);
}
