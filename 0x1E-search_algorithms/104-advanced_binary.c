#include "search_algos.h"

int binary_reccursive(int *array, size_t low, size_t high, int value);

/**
 * advanced_binary - searches for a value in an array of integers
 *                 using the Binary search algorithm.
 *
 * @array: a pointer to the first element of the array to search in.
 *         array is sorted in ascending order.
 * @size: the number of elements in array.
 * @value: the value to search for.
 *
 * Return: the first index where value is located
 *         or -1 if value is not found in array.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_reccursive(array, 0, size - 1, value));
}

/**
 * binary_reccursive - reccursive binary search.
 *                     Must find the leftmost element if
 *                     there are duplicates.
 * @array: The array to search in.
 * @low: The lower bound.
 * @high: The Higher bound.
 * @value: The value to search for.
 *
 * Return: The index of the first element found or -1
 *         uif not found.
 */
int binary_reccursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	print_array(array, low, high);
	if (high > low)
	{
		mid = (low + high) / 2;
		if (array[mid] < value)
			return (binary_reccursive(array, mid + 1,  high, value));
		else
			return (binary_reccursive(array, low, mid, value));
	}

	if (array[low] == value)
		return (low);
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
