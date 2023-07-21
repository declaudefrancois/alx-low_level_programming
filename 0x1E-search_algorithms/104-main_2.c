#include <stdio.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int array[17] = {
		3, 4, 5, 7, 7, 7, 8, 9, 10, 11, 21, 33, 33, 33, 35, 44, 51
	};
	printf("Found at index: %d\n", advanced_binary(array, 17, 33));
	return (0);
}
