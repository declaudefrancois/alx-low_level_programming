/**
 * rot13 -  encodes a string using rot13.
 * @s: the string
 *
 * Return: encoded string
 */
char *rot13(char *s)
{
	char *s1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *s2 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i = 0, j;

	while (s[i] != '\0')
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == s1[j])
			{
				s[i] = s2[j];
				break;
			}
		}

		i++;
	}

	return (s);
}
