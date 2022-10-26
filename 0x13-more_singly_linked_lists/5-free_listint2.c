#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and set
 * the head to NULL.
 * @head: A pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *h;

	while (*head != NULL)
	{
		h = *head;
		*head = h->next;
		free(h);
	}

	head = NULL;
}
