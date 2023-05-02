#include "lists.h"

/**
 * free_listint - frees all memory used by a linkedlist
 * @head: the head of the list
 * Return: Nothing
 */

void free_listint(listint_t *head)
{
	while (head != 0)
	{
		listint_t *t = head->next;

		free(head);
		head = t;
	}
}
