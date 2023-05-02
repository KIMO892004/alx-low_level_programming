#include "lists.h"

/**
 * free_listint2 - frees all memory used by a linkedlist
 * @head: the head of the list
 * Return: Nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *t1;

	if (head == 0)
	{
		head = 0;
		return;
	}

	if (*head == 0)
	{
		*head = 0;
		return;
	}

	t1 = *head;

	while (t1 != 0)
	{
		listint_t *t = t1->next;

		free(t1);
		t1 = t;
	}

	*head = 0;
}
