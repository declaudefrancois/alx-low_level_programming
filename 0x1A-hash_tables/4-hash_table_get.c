#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 *
 * @ht: A pointer to the hash table.
 * @key: the key of the item.
 *
 * Return: value associated with the element,
 * or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	int idx;
	hash_node_t *tmp;

	if (ht == NULL)
		return (NULL);

	idx = key_index((unsigned char *) key, ht->size);
	if (ht->array[idx] == NULL)
		return (NULL);
	if (ht->array[idx]->next == NULL)
		return (ht->array[idx]->value);

	tmp = ht->array[idx];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}
