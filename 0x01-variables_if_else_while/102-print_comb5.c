#include <stdio.h>

/**
 * main - print all combinaison of two digit
 *
 * Return: Always 0.
 */
int main(void)
{
	int i = 0, j;
	int c1, c10, c2, c20;

	while (i < 99)
	{
		for (j = i + 1; j < 100; j++)
		{
			if (i < 10)
			{
				c1 = (int) '0';
				c10 = (int) (i + '0');
			}
			else
			{
				c1 = (int) (i / 10 + '0');
				c10 = (int) (i % 10 + '0');
			}

			putchar(c1);
			putchar(c10);
			putchar(' ');

			if (j < 10)
			{
				c2 = (int) '0';
				c20 = (int) j + '0';
			}
			else
			{
				c2 = (int) (j / 10 + '0');
				c20 =(int) (j % 10 + '0');
			}
			putchar(c2);
			putchar(c20);

			if (!(i == 98 && j == 99))
			{
				putchar(',');
				putchar(' ');
			}

			if (j == 99)
				i++;
		}
	}
	putchar('\n');
	return (0);
}
