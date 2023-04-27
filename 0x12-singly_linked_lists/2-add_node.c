#include "lists.h"

/**
 * add_node - adds a node to the start of the list
 * @headdd: the address of the pointer to the head node
 * @strr: strr field of the node
 *
 * Return: size of the list
 */
list_t *add_node(list_t **headdd, const char *strr)
{
	list_t *new_headdd = malloc(sizeof(list_t));

	if (!headdd || !new_headdd)
		return (NULL);
	if (strr)
	{
		new_headdd->strr = strdup(strr);
		if (!new_headdd->strr)
		{
			free(new_headdd);
			return (NULL);
		}
		new_headdd->len = _strlen(new_headdd->strr);
	}

	new_headdd->next = *headdd;
	*headdd = new_headdd;
	return (new_headdd);
}
