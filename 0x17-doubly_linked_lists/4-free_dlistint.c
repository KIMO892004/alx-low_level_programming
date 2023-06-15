#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - free a dlistint_t list
 * @head: the pointer to the beginning of the linked list
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *nextt;

	while (head != NULL)
	{
		nextt = head->nextt;
		free(head);
		head = nextt;
	}
}
