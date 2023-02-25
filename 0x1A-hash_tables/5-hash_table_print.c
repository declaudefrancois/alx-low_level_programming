#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 *
 * @ht: A pointer to the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp;
	int is_first;
	unsigned long int i;

	if (ht == NULL)
		return;

	is_first = 1;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			if (!is_first)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			if (is_first)
				is_first = 0;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
