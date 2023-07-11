#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 *
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in array.
 * @value: the value to search for.
 *
 * Return: the index where value is located or -1 if value is not
 *         found in array.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, j, m, min_msize;

	if (array == NULL)
		return (-1);

	i = 0;
	m = sqrt(size);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	while (array[min_msize - 1] < value)
	{
		if (i > 0)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i = m;
		m += sqrt(size);
		if (i >= size)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, m);
			return (-1);
		}
		min_msize = m > size ? size : m;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, m);

	j = i;
	while (array[j] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
		j++;
	}

	return (-1);
}
