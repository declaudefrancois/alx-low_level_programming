/**
 * factorial - calculate factorial of n.
 * @n: the number to calculate factorial for.
 *
 * Return: int , n!
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
