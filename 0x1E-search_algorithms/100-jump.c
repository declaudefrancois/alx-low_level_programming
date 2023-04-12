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
	size_t i, j, m;

	if (array == NULL)
		return (-1);

	i = 0;
	m = sqrt(size);
	while (m < size - 1)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
		else if (array[m] < value)
		{
			i = m;
			m += sqrt(size);
		}
		else
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, m);
			for (j = i; j <= m; j++)
			{
				printf("Value checked array[%ld] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
			}
			return (-1);
		}
	}

	return (-1);
}
