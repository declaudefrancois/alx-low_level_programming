#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers
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
int binary_search(int *array, size_t size, int value)
{
	size_t left_idx, right_idx, middle;

	if (array == NULL)
		return (-1);

	left_idx = 0;
	right_idx = size - 1;
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
