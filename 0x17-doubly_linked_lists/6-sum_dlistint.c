#include "lists.h"

/**
 * sum_dlistint - the sum of all the data (n)
 * of a dlistint_t linked list.
 *
 * @head: A pointer to the head of the list.
 *
 * Return: The resulting sum.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
