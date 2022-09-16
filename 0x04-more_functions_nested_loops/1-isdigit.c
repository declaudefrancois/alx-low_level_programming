/**
 * _isdigit - check if a int represent a number
 *
 * @c: the number to check
 *
 * Return: int 0 or 1.
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}

