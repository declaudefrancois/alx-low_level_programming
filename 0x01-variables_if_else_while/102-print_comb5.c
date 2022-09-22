#include <stdio.h>

/**
 * main - print all combinaison of two digit
 *
 * Return: Always 0.
 */
int main(void)
{
	int i = 0;

	while (i < 100)
	{
		if (i > 10)
		{
			putchar(i / 10 + '0');
			putchar(i % 10 + '0');
		}
		else
		{
			putchar('0');
			putchar(i + '0');
		}

		if (i != 99)
		{
			putchar(',');
			putchar(' ');
		}
		else
			putchar('\n');

		i++;
	}

	return (0);
}
