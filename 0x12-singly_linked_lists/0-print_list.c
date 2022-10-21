#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list.
 * @h: A pointer to the head of list_t list.
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	list_t l;
	unsigned int i = 0;

	if (h == NULL)
		return (0);

	l = *h;
	while (1)
	{
		i++;
		if (l.str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", l.len, l.str);

		if (l.next == NULL)
			break;
		l = *l.next;
	}

	return (i);
}
