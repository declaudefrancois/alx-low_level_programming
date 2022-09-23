/**
 * cap_string - capitalize a string
 * @s: a pointer to the string
 *
 * Return: a pointer to s
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (!(s[i] >= 'a' && s[i] <= 'z'))
		{
			i++;
			continue;
		}

		if (i == 0 ||
		    s[i - 1] == ' ' ||
		    s[i - 1] == '\n' ||
		    s[i - 1] == '\t' ||
		    s[i - 1] == ',' ||
		    s[i - 1] == ';' ||
		    s[i - 1] == '.' ||
		    s[i - 1] == '?' ||
		    s[i - 1] == '"' ||
		    s[i - 1] == '(' ||
		    s[i - 1] == ')' ||
		    s[i - 1] == '{' ||
		    s[i - 1] == '}' ||
		    s[i - 1] == '!')
			s[i] -= 32;

		i++;
	}
	return (s);
}
