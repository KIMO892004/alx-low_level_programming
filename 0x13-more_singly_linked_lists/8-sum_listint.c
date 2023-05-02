#include "lists.h"

/**
 * sum_listint - return the sum of all nodes value
 * @head:the head of the linkedlist
 *
 * Return: the sum of all node values
 */

int sum_listint(listint_t *head)
{
	int summ = 0;

	if (head == 0)
		return (summ);

	while (head != 0)
	{
		summ += head->n;
		head = head->next;
	}

	return (summ);
}
