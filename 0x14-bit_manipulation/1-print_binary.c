#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <limits.h>


/**
 * recursive_print_binary - recusively prints the binary representation
 *                          of a number.
 * @n: The number, greather than 0.
 */
void recursive_print_binary(unsigned long int n)
{
	if (n == 0)
		return;

	recursive_print_binary(n >> 1);
	printf("%d", (n & 1) ? 1 : 0);
}


/**
 * print_binary - prints the binary representation of a number.
 *
 * @n: The number.
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		printf("0");
		return;
	}

	recursive_print_binary(n);
}
