#include "lists.h"
/**
 * add_node - adds a new node at the beninning
 * @headd: head of the linked list
 * @strr: string to store in the list
 * Return: the address of the head.
 */

list_t *add_node(list_t **headd, const char *strr)
{
	list_t *new;
	size_t nchar;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->strr = strdup(strr);

	for (nchar = 0; strr[nchar]; nchar++)
		;

	new->len = nchar;
	new->next = *headd;
	*headd = new;

	return (*headd);
}
