/**
 * _isupper - check if a string is uppercase
 * @c: the char to check
 *
 * Return: 0 or 1.
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);

	return (0);
}
