#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: a pointer to the string to search in.
 * @accept: the set of char to look for.
 *
 * Return: A pointer the first byte that matches one of accept
 * bytes or NULL if no such bytes found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0, j;

	while (s[i] != '\0')
	{
		j = 0;

		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (&(*(s + i)));
			j++;
		}

		i++;
	}

	return (NULL);
}
