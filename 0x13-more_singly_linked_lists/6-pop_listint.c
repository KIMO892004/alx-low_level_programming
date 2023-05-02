#include "lists.h"

/**
 * pop_listint - deletes the head of a linkedlist
 * @head: the head of the linkedlist
 * Return: the value of the head that was remove
 */

int pop_listint(listint_t **head)
{
	listint_t *t;
	int v;

	if (head == 0 || *head == 0)
		return (0);
	v = (*head)->n;
	t = (*head)->next;

	free(*head);
	*head = t;

	return (v);
}
