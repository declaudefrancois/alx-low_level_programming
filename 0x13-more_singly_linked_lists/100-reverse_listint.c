#include "lists.h"

/**
 * reverse_listint -  reverses a listint_t linked list.
 *
 * @head: A double pointer to the head of the list.
 * Return: a pointer to the head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev, *curr, *next;

	if (!head || !*head)
		return (NULL);

	prev = *head;
	curr = prev->next;
	next = curr ? curr->next : NULL;
	prev->next = NULL;

	while (next && next->next)
	{
		/**
		 * printf("%d <- %d\n", prev->n, curr->n);
		 */
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}

	if (curr)
	{
		/**
		 * printf("%d <- %d\n", prev->n, curr->n);
		 */
		curr->next = prev;
	}
	if (next)
	{
		/**
		 * printf("%d <- %d\n", curr->n, next->n);
		 */
		next->next = curr;
	}


	*head = next ? next : (curr ? curr : prev);
	return (*head);
}
