#include <stdio.h>

/**
 * _strspn - that gets the length of a prefix substring.
 * @s: the string
 * @accept: the accepted bytes char.
 *
 * Return: int the number of bytes.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n_bytes = 0;
	int i = 0, j;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break;
			j++;
		}

		if (s[i] == accept[j])
			break;
		i++;
	}

	if (s[i] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				n_bytes += sizeof(char);
				break;
			}
			j++;
		}
		if (s[i] != accept[j])
			break;
		i++;
	}

	return (n_bytes);
}
