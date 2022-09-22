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
			c1 = i < 10 ? (int) '0' : (int) (i / 10 + '0');
			c10 = i < 10 ? (int) (i + '0') : (int) (i % 10 + '0');

			putchar(c1);
			putchar(c10);
			putchar(' ');

			c2 = j < 10 ? (int) '0' : (int) (j / 10 + '0');
			c20 = j < 10 ? (int) (j + '0') : (int) (j % 10 + '0');

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
