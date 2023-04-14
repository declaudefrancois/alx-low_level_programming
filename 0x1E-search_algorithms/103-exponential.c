#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm.
 *
 * @array: a pointer to the first element of the array to search in.
 * @size: number of elements in array.
 * @value: the value to search for.
 *
 * Return: the first index where value is located OR -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, high;

	if (array == NULL)
		return (-1);
	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	high = bound > size ? size - 1 : bound - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", bound / 2, high);
	return (binary_search_bound(array, bound / 2, high, value));
}

/**
 * binary_search_bound - searches for a value in an array of integers
 *                 using the Binary search algorithm.
 *
 * @array: a pointer to the first element of the array to search in.
 *         array is sorted in ascending order.
 * @min: the lower bound index from which to start.
 * @max: the upper bound index at which to stop.
 * @value: the value to search for.
 *
 * Return: the first index where value is located
 *         or -1 if value is not found in array.
 */
int binary_search_bound(int *array, size_t min, size_t max, int value)
{
	size_t left_idx, right_idx, middle;

	if (array == NULL)
		return (-1);

	left_idx = min;
	right_idx = max - 1;
	while (left_idx <= right_idx)
	{
		print_array(array, left_idx, right_idx);
		middle = (left_idx + right_idx) / 2;

		if (array[middle] == value)
			return (middle);
		else if (array[middle] > value)
			right_idx = middle - 1;
		else
			left_idx = middle + 1;
	}

	return (-1);
}


/**
 * print_array - prints the portion of the array between
 *               start and end indexes.
 *
 * @array: the array to print.
 * @start: the element's index to print.
 * @end: the last element's index to print.
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}
