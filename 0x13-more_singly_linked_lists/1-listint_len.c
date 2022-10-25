#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes.
 */
size_t listint_len(const listint_t *h)
{
	listint_t *c;
	int len = 0;

	if (h == NULL)
		return (0);

	len++;
	c = h->next;
	while (c != NULL)
	{
		len++;
		c = c->next;
	}

	return (len);
}

