#include "lists.h"

/**
 * add_nodeint_end - adds a node to the bottom
 * @heading: the pointer to the first node
 * @num: the value for new node
 *
 * Return: the pointer to new node
 */
listint_t *add_nodeint_end(listint_t **heading, const int num)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *node;

	if (!heading || !new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->num = num;
	if (!*heading)
		*heading = new_node;
	else
	{
		node = *heading;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	return (new_node);
}
