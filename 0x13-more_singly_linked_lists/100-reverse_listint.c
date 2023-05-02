#include "lists.h"

/**
 * reverse_listint - reverses a linkedlist
 * @head: the head of the list
 * Return: the head of the list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *p = 0, *next = 0;

	if (head == 0 || *head == 0)
		return (0);

	while (*head != 0)
	{
		next = (*head)->next;
		(*head)->next = p;
		p = *head;
		*head = next;
	}
	*head = p;

	return (*head);
}
