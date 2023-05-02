#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @r: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *r)
{
	size_t num = 0;

	while (r)
	{
	printf("%d\n", r->k);
	num++;
	r = r->nextt;
	}

	return (num);
}
