#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: the double pointer to the beginning of the linked list
 * @idx: the index at which to insert the new node
 * @n: the data to enter into new node
 *
 * Return: the pointer to the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newnode, *next, *current;
	unsigned int k;

	if (h == NULL)
		return (NULL);
	if (idx != 0)
	{
		current = *h;
		for (k = 0; k < idx - 1 && current != NULL; k++)
			current = current->next;
		if (current == NULL)
			return (NULL);
	}
	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (idx == 0)
	{
		next = *h;
		*h = newnode;
		newnode->prev = NULL;
	}
	else
	{
		newnode->prev = current;
		next = current->next;
		current->next = newnode;
	}
	newnode->next = next;
	if (newnode->next != NULL)
		newnode->next->prev = newnode;
	return (newnode);
}
