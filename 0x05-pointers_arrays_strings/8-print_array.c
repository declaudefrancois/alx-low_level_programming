#include <stdio.h>

/**
 * print_array - prints n elt of an array
 * @a: the array
 * @n: the number of items to print
 *
 * Return: void
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("%d", a[i]);

		if (i != n - 1)
			printf(", ");

		i++;
	}

	printf("\n");
}
