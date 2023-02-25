#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 *
 * In case of collision, add the new node at
 * the beginning of the list in that key.
 *
 * @ht: A pointer to the hash table.
 * @key: The key of the new element.
 * @value: Value of key.
 *
 * Return: 1 if success, otherwise 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	int idx;
	hash_node_t *item;

	item = malloc(sizeof(item));
	if (item == NULL)
		return (0);

	item->key = malloc((strlen(key)  + 1) * sizeof(char));
	if (item->key == NULL)
	{
		free(item);
		return (0);
	}

	item->value = malloc((strlen(value) + 1) * sizeof(char));
	if (item->value == NULL && value != NULL)
	{
		if (item->key != NULL)
			free(item->key);
		free(item);
		return (0);
	}

	strcpy(item->key, key);
	strcpy(item->value, value);
	idx = key_index((unsigned char *) item->key, ht->size);

	if (ht->array[idx] == NULL)
		ht->array[idx] = item;
	else
	{
		item->next = ht->array[idx];
		ht->array[idx] = item;
	}

	return (1);
}
