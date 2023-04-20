#include "variadic_functions.h"

/**
 * format_char - formats character
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_char(char *separatorr, va_list app)
{
	printf("%s%c", separatorr, va_arg(app, int));
}

/**
 * format_int - formats integer
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_int(char *separatorr, va_list app)
{
	printf("%s%d", separatorr, va_arg(app, int));
}

/**
 * format_float - formats float
 * @separatorr: the string seprator
 * @app: argument pointer
 */
void format_float(char *separatorr, va_list app)
{
	printf("%s%f", separatorr, va_arg(app, double));
}

/**
 * format_string - formats string
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
 * @formatt: the format string
 */
void print_all(const char * const formatt, ...)
{
	int i = 0, j;
	char *separatorr = "";
	va_list app;
	token_t tokens[] = {
		{"c", formatt_char},
		{"i", formatt_int},
		{"f", formatt_float},
		{"s", formatt_string},
		{NULL, NULL}
	};

	va_start(app, formatt);
	while (formatt && formatt[i])
	{
		j = 0;
		while (tokens[j].token)
		{
			if (formatt[i] == tokens[j].token[0])
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
