#include <stdio.h>
unsigned long int fib(int n);
int first_dec(int n);

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
	double fib_v;
	int i = 2;
	int count = 0, first;

	do {
		fib_v = fib(i);
		first = first_dec((int) fib_v);
		printf("%f", fib_v);

		if (first == 1 || first == 2)
		{
			if (count != 98)
				printf("%d, ",(int) fib_v);
			else
				printf("%d", (int) fib_v);

			count++;
		}	
		
		i++;
	} while (count <= 98);

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


/**
 * first_dec - get the first decimal
 * @n: the number
 *
 * Return: int
 */
int first_dec(int n)
{
	int i = n, n_length = 1, res;

	while (i >= 10)
	{
		i = ((i - (i % 10))) / 10;
		n_length *= 10;
	}

	res = n / n_length;

	return (res > 0 ? res : n % 10);
}
