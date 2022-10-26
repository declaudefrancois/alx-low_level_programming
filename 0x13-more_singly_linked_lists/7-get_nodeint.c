#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the list's head.
 * @index: The index of the node to find.
 *
 * Return: A pointer to the node found or NULL if the node
 * doesn't exists at the given index.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t n = 0;
	listint_t *h = head;

	while (h != NULL)
	{
		if (index == n)
			return (h);

		h = h->next;
		n++;
	}

	return (NULL);
}
