#include "lists.h"

dlistint_t *_insert_after(dlistint_t *node, int n);

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

	if (h == NULL || *h == NULL)
		return (NULL);

	node = *h;
	pos = 0;
	while (node)
	{
		if (pos == idx)
			return (_insert_after(node, n));
		node = node->next;
		pos++;
	}

	return (NULL);
}

/**
 * _insert_after - Inserts a node after the given one.
 *
 * @node: A non null pointer to the node after whom to
 * insert the new one.
 * @n: The  data member ot the new node.
 *
 * Return: A pointer to the new node or NULL.
 */
dlistint_t *_insert_after(dlistint_t *node, int n)
{
	dlistint_t *new;

	new = malloc(sizeof(new));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = node;
	new->next = node->next;

	if (node->next)
		node->next->prev = new;
	node->next = new;

	return (new);
}

