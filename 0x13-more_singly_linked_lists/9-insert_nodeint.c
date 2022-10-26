#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the list's head.
 * @idx: The index of the node to insert.
 * @n: The data of the node (n member, value).
 *
 * Return: A pointer to the added node or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *h = *head;
	listint_t *node = malloc(sizeof(listint_t *));
	listint_t *prevNode = NULL;
	size_t cursor = 0;

	if (node == NULL || head == NULL)
		return (NULL);

	while (h != NULL)
	{
		if (cursor == idx)
			break;

		prevNode = h;
		h = prevNode->next;
		cursor++;
	}

	if (cursor == idx)
	{
		node->n = n;
		node->next = h;
		if (prevNode != NULL)
			prevNode->next = node;
		else if (idx == 0)
			*head = node;

		return (node);
	}

	free(node);
	return (NULL);
}
