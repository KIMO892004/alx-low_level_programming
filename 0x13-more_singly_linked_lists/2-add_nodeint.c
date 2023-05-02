#include "lists.h"

/**
 * add_nodeint - adds a node to the top
 * @head: the pointer to the first node
 * @n: the value for new node
 *
 * Return: the pointer to new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!head || !new_node)
		return(0);

	new_node->next = 0;
	new_node->n = n;
	if (*head)
		new_node->next = *head;
	*head = new_node;
	return (new_node);
}
