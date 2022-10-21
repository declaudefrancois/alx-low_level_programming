#include "lists.h"

/**
 * free_list - Frees memory used by a list_t linked list.
 * @head: A pointer to the head of the list.
 */
void free_list(list_t *head)
{
	list_t *h = head;
	while (h != NULL)
	{
		free(h->str);
		free(h);
		h = h->next;
	}
}
