#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the hash table
 *
 * Return: the pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int k;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);
	sht->size = size;
	sht->shead = NULL;
	sht->stail = NULL;
	sht->array = malloc(sizeof(shash_node_t) * size);
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}
	for (k = 0; k < size; k++)
	{
		sht->array[k] = NULL;
	}
	return (sht);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: the key for the data
 * @value: the data to be stored
 *
 * Return: the pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *sh;

	sh = malloc(sizeof(shash_node_t));
	if (sh == NULL)
		return (NULL);
	sh->key = strdup(key);
	if (sh->key == NULL)
	{
		free(sh);
		return (NULL);
	}
	sh->value = strdup(value);
	if (sh->value == NULL)
	{
		free(sh->key);
		free(sh);
		return (NULL);
	}
	sh->next = sh->snext = sh->sprev = NULL;
	return (sh);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *tmpp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	tmpp = table->shead;
	while (tmpp != NULL)
	{
		if (strcmp(node->key, tmpp->key) < 0)
		{
			node->snext = tmpp;
			node->sprev = tmpp->sprev;
			tmpp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		tmpp = tmpp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: the sorted hash table
 * @key: the key to the data
 * @value: the data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int theindex;
	char *new_value;
	shash_node_t *sh, *tmpp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	theindex = key_index((const unsigned char *)key, ht->size);
	tmpp = ht->array[theindex];
	while (tmpp != NULL)
	{
		if (strcmp(tmpp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmpp->value);
			tmpp->value = new_value;
			return (1);
		}
		tmpp = tmpp->next;
	}
	sh = make_shash_node(key, value);
	if (sh == NULL)
		return (0);
	sh->next = ht->array[theindex];
	ht->array[theindex] = sh;
	add_to_sorted_list(ht, sh);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: the hash table
 * @key:the key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int theindex;
	shash_node_t *tmpp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	theindex = key_index((const unsigned char *)key, ht->size);
	tmpp = ht->array[theindex];
	while (tmpp != NULL)
	{
		if (strcmp(tmpp->key, key) == 0)
			return (tmpp->value);
		tmpp = tmpp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: the hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmpp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmpp = ht->shead;
	while (tmpp!= NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmpp->key, tmpp->value);
		flag = 1;
		tmpp = tmpp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
