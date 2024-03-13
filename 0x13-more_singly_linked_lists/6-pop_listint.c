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
	listint_t *prev_head;
	int n;

	if (*head == NULL)
		return (0);

	prev_head = *head;
	n = (*head)->n;
	if ((*head)->next)
		*head = (*head)->next;
	free(prev_head);

	return (n);
}
