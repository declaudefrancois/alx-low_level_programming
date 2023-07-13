#include "search_algos.h"
#include <math.h>

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
	size_t left, right, middle;

	if (array == NULL)
		return (-1);

	left = 0;
	right = size - 1;
	while (left < right)
	{
		print_array(array, left, right);
		middle = floor((left + right) / 2);

		if (array[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}

	if (array[left] == value)
		return (left);
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
