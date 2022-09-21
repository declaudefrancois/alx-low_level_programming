#include "main.h"

/**
 * print_line - print line of n length
 * @n: line length
 *
 * Return: void
 */
void print_line(int n)
{
	int i = 0;

	while (i < n && n != 0)
	{
		_putchar('_');
		i++;
	}

	_putchar('\n');
}
