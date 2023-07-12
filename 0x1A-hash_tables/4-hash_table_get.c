#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the table to retrieve value from
 * @key: the key to find value
 *
 * Return: the value associated with key, or NULL if key cannot be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int theindex;
	hash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	theindex = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[theindex];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
