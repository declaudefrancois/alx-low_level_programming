#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The `n` member value of the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *last;

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	last = last_node(*head);
	if (*head == NULL)
		*head = new;
	else if (last)
		last->next = new;

	return (new);
}

/**
 * last_node - Returns the last node of list_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: A pointer to the last node.
 */
listint_t *last_node(listint_t *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}
