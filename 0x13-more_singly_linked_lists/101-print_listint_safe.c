#include "lists.h"

/**
 * print_listint_safe - prints all nodes of a linkedlist
 * @head: the head of the list
 * Return: the number of node printed
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t l = 0;

	while (head != 0)
	{
		l++;
		printf("[%p] %d\n", (void *)head, head->n);
		if (head > head->next)
			head = head->next;
		else
		{
			head = head->next;
			printf("-> [%p] %d\n", (void *)head, head->n);
			return (l);
		}
	}

	return (l);
}
