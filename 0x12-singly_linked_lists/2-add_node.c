#include "lists.h"

/**
 * add_node - adds a node to the start of the list
 * @head: the address of the pointer to the head node
 * @strr: strr field of node
 *
 * Return: the size of the list
 */
list_t *add_node(list_t **head, const char *strr)
{
	list_t *new_head = malloc(sizeof(list_t));

	if (!head || !new_head)
		return (NULL);
	if (strr)
	{
		new_head->strr = strdup(strr);
		if (!new_head->strr)
		{
			free(new_head);
			return (NULL);
		}
		new_head->len = _strlen(new_head->strr);
	}

	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
