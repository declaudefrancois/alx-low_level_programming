#include "main.h"

/**
 * jack_bauer - Print every mins of 24h
 *
 * Return: void.
 */
void jack_bauer(void)
{
	int i, j, k, l, m;

	for (i = 0; i <= 2; i++)
	{
		m = i == 2 ? 3 : 9;

		for (j = 0; j <= m; j++)
		{
			for (k = 0; k <= 5; k++)
			{
				for (l = 0; l <= 9; l++)
				{
					_putchar(i + '0');
					_putchar(j + '0');
					_putchar(':');
					_putchar(k + '0');
					_putchar(l + '0');
					_putchar('\n');
				}
			}
		}
	}

}

