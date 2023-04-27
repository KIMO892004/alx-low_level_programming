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
	list_t *new_header = malloc(sizeof(list_t));

	if (!header || !new_header)
		return (NULL);
	if (strr)
	{
		new_header->strr = strdup(strr);
		if (!new_header->strr)
		{
			free(new_header);
			return (NULL);
		}
		new_header->len = _strlen(new_header->strr);
	}

	new_header->next = *header;
	*header = new_header;
	return (new_header);
}
