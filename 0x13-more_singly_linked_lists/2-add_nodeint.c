#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: Member value of the node to add.
 *
 * Return: A pointer to the new node or NULL.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t *));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	if (head != NULL)
		*head = new;
	return (new);
}
