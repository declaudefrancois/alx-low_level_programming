#include "lists.h"

/**
 * print_dlistint - prints all the elements of a
 * doubly linked list of type dlistint_t.
 *
 * @h: A pointer to the head of the list.
 *
 * Return: The size of the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t size = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		size++;
	}

	return (size);
}
