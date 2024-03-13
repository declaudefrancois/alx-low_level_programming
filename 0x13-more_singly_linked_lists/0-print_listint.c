#include "lists.h"

/**
 * print_listint -  prints all the elements of a listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	int length = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		length++;
	}

	return (length);
}
