#include "main.h"

/**
 * print_last_digit - last digit of number
 * @n: int to get last digit
 *
 * Return: int
 */
int print_last_digit(int n)
{
	int last_digit = n < 0 ? -n % 10 : n % 10;

	_putchar(last_digit + '0');
	return (last_digit);
}

