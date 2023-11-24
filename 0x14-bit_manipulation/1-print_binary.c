#include "main.h"
#include <stdio.h>


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
	_putchar((n & 1) ? '1' : '0');
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
		_putchar('0');
		return;
	}

	recursive_print_binary(n);
}
