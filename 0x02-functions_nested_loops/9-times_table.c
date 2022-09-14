#include "main.h"
void print_number(int n);

/**
 * times_table - 9 times tables
 *
 * Return: void
 *
 */
void times_table(void)
{
	int x, y, res;

	for (x = 0; x <= 9; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			res = x * y;

			if (y != 0 && (res / 10) == 0)
			{
				_putchar(' ');
				_putchar(' ');
			}
			else if (y != 0 && (res / 10) > 0)
			{
				_putchar(' ');
			}

			print_number(res);

			if (y != 9)
				_putchar(',');
		}

		_putchar('\n');
	}
}

/**
 * print_number - print an in number
 * @n: the number to print
 * Return: void
 */
void print_number(int n)
{
	int i = n, n_length = 1;

	while (i >= 10)
	{
		i = ((i - (i % 10))) / 10;
		n_length *= 10;
	}

	i = n;
	while (n_length >= 10)
	{
		int res = i / n_length;

		_putchar(res + '0');

		i -= res * n_length;
		n_length /= 10;
	}

	_putchar((n % 10) + '0');
}
