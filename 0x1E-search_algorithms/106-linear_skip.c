#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted
 *               skip list of integers.
 *
 * @list: A pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer on the first node where
 *         value is located or NULL if not
 *         found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (list == NULL)
		return (NULL);

	while (list->express && list->express->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n",
		       list->express->index, list->express->n);
		list = list->express;
	}

	if (list->express)
		printf("Value found between indexes [%ld] and [%ld]\n",
		       list->index, list->express->index);

	while (list && list->n <= value)
	{
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
