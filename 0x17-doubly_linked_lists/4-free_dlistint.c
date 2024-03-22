#include "lists.h"

/**
 * free_dlistint -  frees a dlistint_t list.
 *
 * @head: A pionter to the head of the list to free.
 */
void free_dlistint(dlistint_t *head)
{
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
