#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int k;
	hash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (k = 0; k < ht->size; k++)
	{
		while (ht->array[k] != NULL)
		{
			next = ht->array[k]->next;
			free(ht->array[k]->key);
			free(ht->array[k]->value);
			free(ht->array[k]);
			ht->array[k] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
