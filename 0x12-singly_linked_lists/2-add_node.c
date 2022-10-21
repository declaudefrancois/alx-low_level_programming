#include <string.h>
#include "lists.h"
int _strlen(const char *s);

/**
 * add_node - Adds a node at the begining of list_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @str: The str member of the new node.
 *
 * Return: The Address of the new node or NULL
 * if it failled.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = _strlen(str);
	new->next = *head;
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
