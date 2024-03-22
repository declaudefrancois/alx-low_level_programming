#include "lists.h"

/**
 * dlistint_len - returns the numbers of nodes
 * in a doubly linked list of type dlistint_t.
 *
 * @h: A pointer t o the head of the list.
 *
 * Return: The size of the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t size = 0;

	while (h)
	{
		h = h->next;
		size++;
	}
	return (size);
}
