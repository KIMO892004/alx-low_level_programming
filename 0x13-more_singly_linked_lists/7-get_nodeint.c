#include "lists.h"

/**
 * get_nodeint_at_index - return the node at nth index
 * @head: the head of the linkedlist
 * @index: the index of node to be return
 *
 * Return: node at the index
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int curr_idx = 0;

	while (head != 0)
	{
		if (curr_idx == index)
			return (head);
		curr_idx++;
		head = head->next;
	}

	return (0);
}
