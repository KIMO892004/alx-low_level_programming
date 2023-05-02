#include "lists.h"

/**
 * print_listint - prints all of the elements of a linked list
 * @h: linked list of type listint_t to the print
 *
 * Return: number of the nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
	printf("%d\n", h->n);
	num++;
	h = h->nextt;
	}

	return (num);
}
