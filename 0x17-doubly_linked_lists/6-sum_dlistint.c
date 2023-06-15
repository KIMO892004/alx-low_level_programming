#include "lists.h"

/**
 * sum_dlistint - sums all of the data of a dlistint_t linked list
 * @head: the pointer to the beginning of the linked list
 *
 * Return: the sum of all data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int summ = 0;

	while (head != NULL)
	{
		summ += head->n;
		head = head->next;
	}
	return (summ);
}
