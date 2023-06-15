#include "lists.h"

/**
 * dlistint_len - counting the number of nodes in the linked list
 * @h: the pointer to the beginning of a linked list
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t k;

	for (k = 0; h != NULL; k++)
		h = h->next;
	return (k);
}
