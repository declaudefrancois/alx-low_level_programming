#include "main.h"

/**
 * more_numbers - print 10x from 0 to 14
 *
 * Return: Always void
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		j = 0;

		while (j <= 14)
		{
			_putchar(j + '0');
			j++;
		}

		_putchar('\n');
		i++;
	}
}
