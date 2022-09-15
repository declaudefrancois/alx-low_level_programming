#include "main.h"
void print_number(int n);

/**
 * print_times_table - n times table
 * @n: the number
 * Return: void
 *
 */
void print_times_table(int n)
{
	int x, y, res;

	if (n < 0 || n > 15)
		return;

	for (x = 0; x <= n; x++)
	{
		for (y = 0; y <= n; y++)
		{
			res = x * y;

			if (y != 0)
			{
				int i = res, length = 3;

				do {
					i = ((i - (i % 10))) / 10;
					length--;
				} while (i > 0);

				while (length >= 0)
				{
					_putchar(' ');
					length--;
				}

			}

			print_number(res);

			if (y != n)
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

