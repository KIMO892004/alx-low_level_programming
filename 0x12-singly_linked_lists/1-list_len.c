#include "lists.h"

/**
 * list_len - determines the length of linked list
 * @r: the pointer to the first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *r)
{
	size_t i = 0;

	while (r)
	{
		r = r->next;
		i++;
	}
	return (i);
}
