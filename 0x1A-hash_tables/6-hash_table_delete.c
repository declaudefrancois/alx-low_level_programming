#include "hash_tables.h"

void free_item(hash_node_t *item);

/**
 * hash_table_delete - deletes a hash table.
 *
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp = NULL, *tmp1 = NULL;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			tmp1 = tmp->next;
			free_item(tmp);
			tmp = tmp1;
		}
	}

	free(ht->array);
	free(ht);
}


/**
 * free_item - frees one item of a hash table.
 *
 * @item: The item to free.
 */
void free_item(hash_node_t *item)
{
	free(item->key);
	free(item->value);
	free(item);
}
