#include "lists.h"

/**
 * insert_nodeint_at_index - insert node at the nth index of a linkedlist
 * @idx: the index where the node should be added
 * @n: the value of the node to be added
 * @head: the head of the list
 * Return: the pointer to the head of the list
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *c, *node;

	if (*head == 0)
		return (0);

	node = malloc(sizeof(*node));

	if (node == 0)
	{
		free(node);
		node = 0;
		return (0);
	}

	node->n = n;
	node->next = 0;
	c = *head;

	if (idx == 0)
	{
		node->next = c;
		*head = node;
		return (*head);
	}

	while (--idx)
	{
		if (c == 0 || c->next == 0)
			return (0);
		c = c->next;
	}
	node->next = c->next;
	c->next = node;
	return (node);
}
