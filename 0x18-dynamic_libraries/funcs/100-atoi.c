/**
 * _atoi - convert a string to int
 * @s: the string to convert
 *
 * Return: the converted int
 */
int _atoi(char *s)
{
	int i =	0;
	unsigned int n = 0;
	int sign = 1;

	/* find the index of the first int. */
	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
			break;

		if (s[i] == '-')
			sign *= -1;

		i++;
	}

	/* find the number from the first index. */
	while (s[i] >= 48 && s[i] <= 57)
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}

	return (n * sign);
}

