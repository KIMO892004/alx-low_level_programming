#include "lists.h"

/**
 * add_node - adds a node to the start of the list
 * @headdd: the address of the pointer to the headdd node
 * @strr: strr field of the node
 *
 * Return: size of list
 */
list_t *add_node(list_t **headdd, const char *strr)
{
	list_t *new_head = malloc(sizeof(list_t));

	if (!headdd || !new_head)
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

	new_head->next = *headdd;
	*headdd = new_head;
	return (new_head);
}
