#include "lists.h"

dlistint_t *_insert_at(dlistint_t **node, int n, int before);

/**
 * insert_dnodeint_at_index -  inserts a new node in a dlistint_t
 * at a given position.
 *
 * @h: A pointer to a pointer to the head of the list.
 * @idx: The index of the new node.
 * @n: The data member ot the new node.
 *
 * Return: A pointer to the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node;
	size_t pos;

	/* Inserting at the beginning of a empty list if idx == 0 */
	if (h == NULL || *h == NULL)
		return (idx == 0 ? _insert_at(h, n, 0) : NULL);

	/* Inserting at the beginning of an non empty list */
	if (idx == 0)
	{
		*h = _insert_at(h, n, 1);
		return (*h);
	}

	node = *h;
	pos = 1;
	while (node)
	{
		if (pos == idx)
			return (_insert_at(&node, n, 0));
		node = node->next;
		pos++;
	}

	/* Inserting at the end of the list if idx == list size */
	return (idx == pos + 1 ? _insert_at(h, n, 0) : NULL);
}

/**
 * _insert_at - Inserts a node after or before the given one.
 *
 * @node: A non null pointer to a pointer the node after
 * whom to insert the new one.
 *
 * @n: The  data member ot the new node.
 * @before: 1 if the node will be inserted before, 0 if after
 * default to 0.
 *
 * Return: A pointer to the new node or NULL.
 */
dlistint_t *_insert_at(dlistint_t **node, int n, int before)
{
	dlistint_t *new;

	new = malloc(sizeof(new));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (node == NULL)
	{
		node = &new;
		return (new);
	}
	else if (*node == NULL)
	{
		*node = new;
		return (new);
	}

	if (before)
	{
		if ((*node)->prev)
		{
			(*node)->prev->next = new;
			new->prev = (*node)->prev;
		}
		new->next = *node;
		(*node)->prev = new;
	}
	else
	{
		if ((*node)->next)
		{
			(*node)->next->prev = new;
			new->next = (*node)->next;
		}
		new->prev = *node;
		(*node)->next = new;
	}
	return (new);
}

