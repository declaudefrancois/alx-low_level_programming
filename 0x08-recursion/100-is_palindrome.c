int _strlen_recursion(char *s);
int cmp_inv(char *s, int length);

/**
 * is_palindrome - check if string is aa palindrome
 * @s: string to check
 *
 * Return: 1 if true otherwise 0.
 */
int is_palindrome(char *s)
{
	int sl = _strlen_recursion(s);

	return (cmp_inv(s, sl - 1));
}

/**
 * cmp_inv - compare each string char with it's
 * opposite.
 * @s: the string
 * @length: string's length.
 *
 * Return: 1 if all opposite char are equals
 * Otherwise 0.
 */
int cmp_inv(char *s, int length)
{
	if (length < 1)
		return (1);

	if (*s != *(s + length))
		return (0);

	return (cmp_inv(s + 1, length - 2));
}

/**
 * _strlen_recursion - lenght of a string with recusrion
 * @s: the string.
 *
 * Return: int , the string length.
 */
int _strlen_recursion(char *s)
{
	int l = 0;

	if (*s != '\0')
	{
		return (1 + _strlen_recursion((s + 1)));
		l++;
	}

	return (0);
}
