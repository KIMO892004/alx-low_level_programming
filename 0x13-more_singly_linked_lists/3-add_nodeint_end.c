#include "lists.h"

/**
 * add_nodeint_end - adds a node to the bottom
 * @head: the pointer to the first node
 * @n: the value for new node
 *
 * Return: the pointer to new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *node;

	if (!head || !new_node)
		return (0);

	new_node->next = 0;
	new_node->n = n;
	if (!*head)
		*head = new_node;
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	return (new_node);
}
