#include <stdio.h>
unsigned long int fib(int n);

/**
 * main - Entry point
 *
 * Fibonacci suite.
 *
 * Return: Always 0.
 *
 */
int main(void)
{
	int n = 1;

	while (n <= 50)
	{
		printf("%ld", fib(n));
		if (n < 50)
			printf(", ");
		n++;
	}

	printf("\n");

	return (0);
}

/**
 * fib - calculate the n-th  fibonacci number.
 * @n: the n-th fibonacci number.
 *
 * Return: int.
 */
unsigned long int fib(int n)
{
	unsigned long int x1 = 0, x2 = 1, x3;
	int i;

	if (n == 0 || n == 1)
		return (n);

	for (i = 0; i < n; i++)
	{
		x3 = x2 + x1;
		x1 = x2;
		x2 = x3;
	}

	return (x3);
}
