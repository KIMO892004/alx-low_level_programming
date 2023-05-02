#include "lists.h"

/**
 * add_nodeint - adds a node to the top
 * @headd: pointer to the first node
 * @r: value for a new node
 *
 * Return: pointer to the new node
 */
listint_t *add_nodeint(listint_t **headd, const int r)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!headd || !new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->r = r;
	if (*headd)
		new_node->next = *headd;
	*headd = new_node;
	return (new_node);
}
