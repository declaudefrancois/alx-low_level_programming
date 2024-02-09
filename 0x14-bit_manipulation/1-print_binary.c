#include "main.h"

/**
 * print_binary - Prints the binary representation of number.
 * @n: The number to print.
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	print_binary_recursive(n);
}


/**
 * print_binary_recursive - Recursively prints the binary representation
 *                          of number.
 * @n: The number to print (must be greather than 0).
 */
void print_binary_recursive(unsigned long int n)
{
	if (n == 0)
		return;
	print_binary_recursive(n >> 1);
	_putchar(n & 1 ? '1' : '0');
}
