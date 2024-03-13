#include "lists.h"
#include <stdio.h>

/**
 * delete_nodeint_at_index - deletes the node at index
 * index of a listint_t linked list.
 *
 * @head: A double pointer to the headof the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int cursor;
	listint_t *curr, *prev;

	curr = head ? *head : NULL;
	prev = curr;
	cursor = 0;
	while (curr && cursor < index)
	{
		prev = curr;
		curr = curr->next;
		cursor++;
	}

	if (curr && cursor == index)
	{
		if (index == 0)
			*head = (*head)->next;
		else
			prev->next = curr->next;
		free(curr);
		return (1);
	}

	return (-1);
}
