#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a
 * doubly linked list of type dlistint_t.
 *
 * @head: A pointer to a pointer to the head of the list.
 * @n: The data member of the new node.
 *
 * Return: The newly added node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node;
	dlistint_t *tmp;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	if (head == NULL)
		head = &node;
	else if (*head == NULL)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		node->prev = tmp;
		tmp->next = node;
	}

	return (node);
}
