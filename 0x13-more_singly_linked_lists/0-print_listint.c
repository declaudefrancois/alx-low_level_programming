#include "lists.h"

/**
 * print_listint -  prints all the elements of a listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	listint_t *current;
	int length = 0;

	if (h == NULL)
		return (0);

	length++;
	printf("%d\n", h->n);
	current = h->next;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		length++;
	}

	return (length);
}
