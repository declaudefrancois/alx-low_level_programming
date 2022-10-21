#include <string.h>
#include "lists.h"
int _strlen(const char *s);
list_t *last_node(list_t *head);

/**
 * add_node_end - Adds a node at the end of list_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @str: The str member of the new node.
 *
 * Return: The Address of the new node or NULL
 * if it failled.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *last;

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = _strlen(str);
	new->next = NULL;

	last = last_node(*head);
	if (head != NULL && last != NULL)
		last->next = new;
	else
		*head = new;
	return (new);
}


/**
 * _strlen - string length
 * @s: The string to get the length.
 *
 * Return: int, the string's length.
 */
int _strlen(const char *s)
{
	int i = 0, size = 0;

	while (s[i] != '\0')
	{
		size++;
		i++;
	}

	return (size);
}


/**
 * last_node - Returns the last node of list_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: A pointer to the last node.
 */
list_t *last_node(list_t *head)
{
	list_t *n;

	if (head == NULL)
		return (NULL);
	n = head;
	while (n->next != NULL)
		n = n->next;
	return (n);
}
