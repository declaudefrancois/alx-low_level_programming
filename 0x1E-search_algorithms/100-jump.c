#include <math.h>
#include "search_algos.h"


size_t min(size_t a, size_t b);


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
	size_t low, high;
	const size_t k = sqrt(size);

	if (array == NULL)
		return (-1);

	high = k;
	low = 0;
	while (size > 0 && array[min(high, size) - 1] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", low, array[low]);
		low = high;
		high += k;
		if (low >= size)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", low, high);
			return (-1);
		}
		if (array[min(high, size) - 1] >= value)
			printf("Value checked array[%ld] = [%d]\n", low, array[low]);
	}

	printf("Value found between indexes [%ld] and [%ld]\n", low, high);
	while (array[low] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", low, array[low]);
		if (array[low] == value)
			return (low);
		low++;
	}

	return (-1);
}


/**
 * min - Return the minimum of two numbers.
 *
 * @a: First number.
 * @b: Second number.
 *
 * Return: The smalest between a and b.
 */
size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}
