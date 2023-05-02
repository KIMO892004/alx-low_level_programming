#include "lists.h"

/**
 * listint_len - prints a linked lists
 * @k: pointer to the first node
 *
 * Return: size of the list
 */
size_t listint_len(const listint_t *k)
{
	size_t i = 0;

	while (k)
	{
		k = k->next;
		i++;
	}
	return (i);
}
