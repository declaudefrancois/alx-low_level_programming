#include "lists.h"

/**
 * sum_listint - Returns the sum of all the
 * data (n) of a listint_t linked list.
 * @head: A pointer to the list's head.
 *
 * Return: The sum of all data.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *h = head;

	while (h != NULL)
	{
		sum += h->n;
		h = h->next;
	}

	return (sum);
}
