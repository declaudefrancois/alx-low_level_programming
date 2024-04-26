#include "hash_tables.h"


/**
 * shash_table_create - Creates a hash table.
 *
 * @size: The size of the table to create.
 *
 * Return: A pointer to the hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->array = malloc(size * sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds a new node in the hash table.
 * @ht: A pointer to the hash table.
 * @key: The key of the node to insert.
 * @value: The value of the node to insert.
 *
 * Return: 1 on success or 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node = NULL, *nodeCursor = NULL;
	int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (1);

	node = create_shash_node(key, value);
	if (node == NULL)
		return (1);

	insert_in_slist(ht, node);

	index = key_index((unsigned char *) node->key, ht->size);
	nodeCursor = ht->array[index];
	/**
	 * If the node (key) exists, update its value.
	 */
	while (nodeCursor)
	{
		if (strcmp(nodeCursor->key, key) == 0)
		{
			free(nodeCursor->value);
			free(node->key);
			nodeCursor->value = node->value;
			free(node);
			return (1);
		}
		nodeCursor = nodeCursor->next;
	}

	/**
	 * Otherwise, if the node (key) does not exist
	 * add it a the beginning of the list.
	 */
	node->next = ht->array[index];
	ht->array[index] = node;
	return (1);
}


/**
 * shash_table_get - Retrieves a value associated with a key.
 *
 * @ht: A pointer to the hash table.
 * @key: the key of the item.
 *
 * Return: value associated with the element,
 * or NULL if key couldn’t be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	int idx;
	shash_node_t *tmp = NULL;

	if (ht == NULL)
		return (NULL);

	idx = key_index((unsigned char *) key, ht->size);

	tmp = ht->array[idx];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the the hash table using
 *                     the sorted list.
 * @ht: A pointer to the hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char is_first;

	if (ht == NULL)
		return;
	tmp = ht->shead;

	is_first = 1;
	printf("{");
	while (tmp)
	{
		if (!is_first)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (is_first)
			is_first = 0;
		tmp = tmp->snext;
	}
	printf("}\n");
}


/**
 * shash_table_print_rev - Prints the the hash table in reverse using
 *                         the sorted list.
 * @ht: A pointer to the hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char is_first;

	if (ht == NULL)
		return;
	tmp = ht->stail;

	is_first = 1;
	printf("{");
	while (tmp)
	{
		if (!is_first)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (is_first)
			is_first = 0;
		tmp = tmp->sprev;
	}
	printf("}\n");
}


/**
 * create_shash_node - Creates a nodes an returns a
 *                     pointer to it.
 * @key: The key of the node.
 * @value: The value of the node.
 *
 * Return: A pointer to the create node or NULL.
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = malloc((strlen(key) + 1) * sizeof(char));
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = malloc((strlen(value) + 1) * sizeof(char));
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	strcpy(node->key, key);
	strcpy(node->value, value);
	node->sprev = NULL;
	node->snext = NULL;
	node->next = NULL;

	return (node);
}

/**
 * insert_in_slist - Inserts a node in the sorted list
 *                   of the hash table.
 * @ht: A pointer to the hash table
 * @node: The node to insert.
 */
void insert_in_slist(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *curr;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		node->snext = NULL;
		node->sprev = NULL;
		return;
	}

	curr = ht->shead;
	while (curr != NULL && strcmp(curr->key, node->key) < 0)
		curr = curr->snext;

	if (curr == NULL)
	{
		ht->stail->snext = node;
		node->sprev = ht->stail;
		node->snext = NULL;
		ht->stail = node;
	}
	else if (curr == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		node->sprev = NULL;
	}
	else
	{
		node->snext = curr;
		node->sprev = curr->sprev;
		curr->sprev->snext = node;
		curr->sprev = node;
	}
}



/**
 * shash_table_delete - deletes a hash table.
 *
 * @ht: The hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr = NULL;

	if (ht == NULL)
		return;
	curr = ht->shead;
	while (curr->next)
	{
		curr = curr->next;
		free_item(curr->sprev);
	}

	free(curr);
	free(ht->array);
	free(ht);
}


/**
 * free_item - frees one item of a hash table.
 *
 * @item: The item to free.
 */
void free_item(shash_node_t *item)
{
	free(item->key);
	free(item->value);
	free(item);
}
