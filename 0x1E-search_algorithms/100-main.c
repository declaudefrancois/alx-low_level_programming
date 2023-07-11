#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	int array[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	int arr[] = {
		0, 1, 1, 2, 3, 5, 8, 13, 21,
		34, 55, 89, 144, 233, 377, 610
	};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
	printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
	printf("Found %d at index: %d\n\n", 999, jump_search(array, size, 999));
	printf("Found %d at index: %d\n\n", 13, jump_search(arr, 16, 13));
	printf("Found %d at index: %d\n\n", 55, jump_search(arr, 16, 55));
	printf("Found %d at index: %d\n", 611, jump_search(arr, 16, 611));
	return (EXIT_SUCCESS);
}
