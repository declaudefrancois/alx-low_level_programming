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
	listint_t *tmp, *tmp1;

	tmp = head ? *head : NULL;
	tmp1 = tmp;
	cursor = 0;
	while (tmp && cursor != index)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		cursor++;
	}

	if (tmp && cursor == index)
	{
		if (index == 0)
			*head = (*head)->next;
		if (index > 0)
			tmp1->next = tmp->next;
		free(tmp);
		return (1);
	}

	return (-1);
}
