#include <stdio.h>

/**
 * print_to_98 - print number fom n to 98
 * @n: the start number
 * Return: void
 */
void print_to_98(int n)
{
	int i = n;

	if (i >= 98)
	{
		do {
			printf("%d", i);
			if (i != 98)
				printf(", ");

			i--;
		} while (i >= 98);
	}
	else
	{
		do {
			printf("%d", i);
			if (i != 98)
				printf(", ");

			i++;
		} while (i <= 98);
	}
	printf("\n");
}

