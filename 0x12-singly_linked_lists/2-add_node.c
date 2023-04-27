#include "lists.h"

/**
 * add_node - adds a node to the start of the list
 * @header: the address of the pointer to head node
 * @strr: str field of the node
 *
 * Return: size of list
 */
list_t *add_node(list_t **header, const char *strr)
{
	list_t *new_head = malloc(sizeof(list_t));

	if (!header || !new_head)
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

	new_head->next = *header;
	*header = new_head;
	return (new_head);
}
