#include "lists.h"

/**
 * reverse_listint -  reverses a listint_t linked list.
 *
 * @head: A double pointer to the head of the list.
 * Return: a pointer to the head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *tmp, *tmp1;

	if (!head)
		return (NULL);

	while (*head)
	{
		tmp = (*head)->next;
		(*head)->next = tmp1;
		tmp1 = *head;
		*head = tmp;
	}

	*head = tmp1;
	return (tmp1);
}
