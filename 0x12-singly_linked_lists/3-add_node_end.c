#include "lists.h"

/**
 * add_node_end - adds a node to the end of the list
 * @headd: address of pointer to head node
 * @strr: str field of node
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **headd, const char *strr)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *node = *headd;

	if (!headd || !new_node)
		return (NULL);
	if (strr)
	{
		new_node->strr = strdup(strr);
		if (!new_node->strr)
		{
			free(new_node);
			return (NULL);
		}
		new_node->len = _strlen(new_node->strr);
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*headd = new_node;
	return (new_node);
}
