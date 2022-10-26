#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 * @head: A pointer to a pointer to the head.
 *
 * Return: Data of the deleted head.
 */
int pop_listint(listint_t **head)
{
	listint_t *h;
	int n;

	if (*head == NULL)
		return (0);

	h = *head;
	n = h->n;
	*head = (*head)->next;
	free(h);

	return (n);
}
