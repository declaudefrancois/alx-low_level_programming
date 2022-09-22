/**
 * _strcmp - compare two string
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if string are equals
 * a negative number if s1 is less lenght thant s2
 * a positive number otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int) s1[i] - (int) s2[i]);
		i++;
	}

	if (s1[i] == '\0' && s2[i] != '\0')
		return (0);

	return ((int) s1[i] - (int) s2[i]);
}
