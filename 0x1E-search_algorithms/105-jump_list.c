#include <math.h>
#include "search_algos.h"

listint_t *kth_node(listint_t *node, int k);
size_t min(size_t a, size_t b);

/**
 * jump_list - searches for a value in a sorted list
 *             of integers using the Jump search algorithm.
 *
 * @list: A pointer to he head of the linked list.
 * @size: The number of nodes in list.
 * @value: The value to search for.
 *
 *
 * Return: A pointer to the first node with
 *         the member n equal to value or NULL if
 *         not fount.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t k;
	listint_t *low, *high;

	if (list == NULL)
		return (NULL);

	k = sqrt(size);
	low = list;
	high = kth_node(low, min(k, size) - 1);
	while (high && high->n < value && k < size - 1)
	{
		printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
		low = high;
		k += sqrt(size);
		high = kth_node(low, min(k, size) - 1);
		if (high == NULL)
			return (NULL);
	}

	if (low && low->n < value)
		printf("Value found between indexes [%ld] and [%ld]\n", low->index, k);
	while (low && low->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n", low->index, low->n);
		low = low->next;
	}

	if (low)
		printf("Value checked at index [%ld] = [%d]\n", low->index, low->n);
	return (low && low->n == value ? low : NULL);
}

/**
 * min - Returns the min of a and b.
 * @a: fist number.
 * @b: second number.
 *
 * Return: The min of a and b.
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * kth_node - Get the kth node after node.
 * @node: A pointer the starting node.
 * @k: The relative (to node) position of the node to get.
 *
 * Return: A pointer to the kth node or NULL if not found.
 */
listint_t *kth_node(listint_t *node, int k)
{
	int i;
	listint_t *kth;

	if (node == NULL)
		return (NULL);

	i = node->index;
	kth = node;
	while (kth && i <= k)
	{
		i++;
		kth = kth->next;
	}
	return (kth);
}
