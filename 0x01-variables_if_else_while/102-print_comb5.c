#include <stdio.h>

/**
 * main - print all combinaison of two digit
 *
 * Return: Always 0.
 */
int main(void)
{
	int i, j;
	char c1, c10, c2, c20;

	for (i = 0; i < 99; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (i < 10)
			{
				c1 = '0';
				c10 = i + '0';
			}
			else
			{
				c1 = i / 10 + '0';
				c10 = i % 10 + '0';
			}

			putchar(c1);
			putchar(c10);
			putchar(' ');

			if (j < 10)
			{
				c2 = '0';
				c20 = j + '0';
			}
			else
			{
				c2 = j / 10 + '0';
				c20 = j % 10 + '0';
			}
			putchar(c2);
			putchar(c20);

			if (!(i == 98 && j == 99))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
