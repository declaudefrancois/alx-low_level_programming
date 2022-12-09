#include "lists.h"

/**
 * add_dnodeint - adds a node at the beginning of
 * a doubly linked list.
 *
 * @head: A pointer to a pointer to the head of the list.
 * @n: The data member of the new node.
 *
 * Return: A pointer to the added node or NULL on failure.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(node));
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
		node->n = n;
		node->next = *head;

		(*head)->prev = node;
		*head = node;
	}

	return (*head);
}
