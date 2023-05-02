#include "lists.h"

/**
 * free_listint_safe - prints all nodes of a linkedlist
 * @: the head of the list
 * Return: the number of node printed
 */

size_t free_listint_safe(listint_t **k)
{
	size_t len = 0;

	if (k == 0)
		return (len);

	while (*k != 0)
	{
		listint_t *t;

		len++;
		if (*k > (*k)->next)
		{
			tmp = *k;
			*k = (*k)->next;
			free(t);
		}

		else
		{
			free(*k);
			*k = 0;
		}

	}

	*h = 0;

	return (len);
}
