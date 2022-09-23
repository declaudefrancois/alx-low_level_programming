/**
 * leet - encodes a string into 1337.
 * @s: the string to encode
 *
 * Return:  a pointer to encoded s
 */
char *leet(char *s)
{
	char *a = "aAeEoOtTlL";
	char *b = "4433007711";
	int i = 0, j;

	while (s[i] != '\0')
	{
		for (j = 0; j < 10; j++)
		{
			if (a[j] == s[i])
				s[i] = b[j];
		}

		i++;
	}

	return (s);
}
