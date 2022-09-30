/**
 * wildcmp - compare two string.
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if strings are equal otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
		if (*s2 == '\0')
			return (1);

		return (0);
	}

	if (*s1 == *s2 ||
	    *s1 == '*' ||
	    *s2 == '*')
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
