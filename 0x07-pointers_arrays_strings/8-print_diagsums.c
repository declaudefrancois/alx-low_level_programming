#include <stdio.h>

/**
 * print_diagsums -  prints the sum of the two diagonals of
 * a square matrix of integers.
 * @a: a two dimensional array of size size * size.
 * @size: the size of the array a.
 *
 * Return: void.
 */
void print_diagsums(int *a, int size)
{
	int i, s1 = 0, s2 = 0;

	for (i = 0; i < size; i++)
	{
		s1 += *(a + i * (size + 1));
		s2 += *(a + (i * size) + (size - i - 1));
	}

	printf("%d, %d\n", s1, s2);
}
