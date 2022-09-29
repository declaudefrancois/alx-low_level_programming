int base_sqrt(int n, int x);

/**
 * _sqrt_recursion - sqrt with recursion.
 * @n: the number
 *
 *
 * Return: square root of n.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (base_sqrt(n, 1));
}

/**
 * base_sqrt - guest the square root og n.
 * @n: the number
 * @x: the initial guessed number.
 *
 * Return: int
 */
int base_sqrt(int n, int x)
{
	if (x > n)
		return (-1);

	if (x * x == n)
		return (x);

	return (base_sqrt(n, x + 1));
}
