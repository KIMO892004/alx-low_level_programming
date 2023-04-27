#include "lists.h"

/**
 * _strlen - returns the length of a the string
 * @k: the string whose length to check
 *
 * Return: integer length of the string
 */
int _strlen(char *k)
{
	int i = 0;

	if (!k)
		return (0);
	while (*k++)
		i++;
	return (i);
}

/**
 * print_list - prints a linked lists
 * @r: pointer to the first node
 *
 * Return: the size of the list
 */
size_t print_list(const list_t *r)
{
	size_t i = 0;

	while (r)
	{
		printf("[%d] %s\n", _strlen(r->str), r->str ? r->str : "(nil)");
		r = r->next;
		i++;
	}
	return (i);
}
