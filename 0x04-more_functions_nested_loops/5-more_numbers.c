#include "main.h"

/**
 * more_numbers - print 10x from 0 to 14
 *
 * Return: Always void
 */
void more_numbers(void)
{
	int i, j;
	char last_char;

	for (i = 0; i < 10; i++)
	{
		j = 0;

		while (j <= 14)
		{
			last_char = j + '0';
			if (j / 10 >= 1)
			{
				_putchar('1');
				last_char = j - 10 + '0';
			}

			_putchar(last_char);

			j++;
		}

		_putchar('\n');
	}
}
