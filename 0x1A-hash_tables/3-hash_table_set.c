#include "hash_tables.h"

/**
 * make_hash_node - creates a new hash node
 * @key: the key for the node
 * @value: for the node
 *
 * Return: new node, or NULL on failure
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *thenode;

	thenode = malloc(sizeof(hash_node_t));
	if (thenode == NULL)
		return (NULL);
	thenode->key = strdup(key);
	if (thenode->key == NULL)
	{
		free(thenode);
		return (NULL);
	}
	thenode->value = strdup(value);
	if (thenode->value == NULL)
	{
		free(thenode->key);
		free(thenode);
		return (NULL);
	}
	thenode->next = NULL;
	return (thenode);
}


/**
 * hash_table_set - sets a key to a value in the hash table
 * @ht: the hash table to add elemt to
 * @key: the key for the data
 * @value: the data to store
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int theindex;
	hash_node_t *hash_node, *tmp;
	char *new_value;


	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	theindex = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[theindex];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}
	hash_node = make_hash_node(key, value);
	if (hash_node == NULL)
		return (0);
	hash_node->next = ht->array[theindex];
	ht->array[theindex] = hash_node;
	return (1);
}
