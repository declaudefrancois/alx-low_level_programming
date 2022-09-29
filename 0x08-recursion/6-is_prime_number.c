int prime_helper(int n, int div);

/**
 * is_prime_number - check if number is prime
 * number.
 * @n: the number to check.
 *
 * Return: int 1 if true otherwise 0.
 */
int is_prime_number(int n)
{
	if (n > 1)
		return (prime_helper(n, n - 1));

	return (0);
}

/**
 * prime_helper - helper to check if number is prime.
 * @n: the number.
 * @div: the divider.
 *
 * Return: 1 if true otherwise 0.
 */
int prime_helper(int n, int div)
{
	if (div == 1)
		return (1);

	if (n % div == 0)
		return (0);

	return (prime_helper(n, div - 1));
}
