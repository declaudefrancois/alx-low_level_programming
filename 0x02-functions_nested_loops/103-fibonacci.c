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
	unsigned long int fib_val, sum = 0;
	int i = 2;

	do {
		fib_val = fib(i);
		sum += fib_val % 2 == 0 ? fib_val : 0;
		i++;
	} while (fib_val <= 4e6);

	printf("%ld\n", sum);

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

