/**
 * string_toupper - uppercase a string
 * @s: a pointer to the string
 *
 * Return: a pointer to s
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}

	return (s);

}
