#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 *                        using the Interpolation search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in array.
 * @value: the value to search for.
 *
 * Return: the first index where value is located or -1 if not found.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, mid;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;
	while (value >= array[low] && value <= array[high])
	{
		mid = low + (((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]));
		printf("Value checked array[%ld] = [%d]\n", mid, array[mid]);
		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);
	}

	printf("Value checked array[%ld] is out of range\n", mid);
	return (-1);
}
