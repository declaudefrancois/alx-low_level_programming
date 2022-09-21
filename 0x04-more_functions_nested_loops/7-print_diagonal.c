#include "main.h"

/**
 * print_diagonal - print a diagonal line
 * @n: diagonal length
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i = 0, j;

	if (n == 0)
	{
		_putchar('\n');
		return;
	}

	while (i < n)
	{
		for (j = 1; j <= i; j++)
			_putchar(' ');

		_putchar('\\');
		_putchar('\n');
		i++;
	}
}
