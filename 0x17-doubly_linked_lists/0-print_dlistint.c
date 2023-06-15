#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - printing all the elements of a dlistint_t list
 * @h: the pointer to the start of the linked list
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t k;

	for (k = 0; h != NULL; k++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (k);
}
