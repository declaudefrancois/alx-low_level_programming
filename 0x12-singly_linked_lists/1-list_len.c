#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes.
 */
size_t list_len(const list_t *h)
{
	list_t l;
	unsigned int i = 0;

	if (h == NULL)
		return (0);

	l = *h;
	while (1)
	{
		i++;
		if (l.next == NULL)
			break;
		l = *l.next;
	}
	return (i);
}
