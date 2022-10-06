#include "main.h"

/**
 * array_range - creates an array of integers
 * from min to max.
 *
 * @min: min value.
 * @max: max value.
 *
 * Return: A pointer to the resulting array
 * or NULL if fails.
 */
int *array_range(int min, int max)
{
	int *p;
	int i, j = 0;

	if (min > max)
		return (NULL);

	p = malloc((max - min + 1) * sizeof(int));
	if (p == NULL)
		return (NULL);

	for (i = min; i <= max; i++)
	{
		*(p + j) = i;
		j++;
	}

	return (p);
}
