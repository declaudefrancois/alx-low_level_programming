#include <stddef.h>

/**
 * _strchr -  locates a character in a string.
 * @s: the string to look inside.
 * @c: the char to loook for.
 *
 * Return: A pointer to the first occurence of c or NULL is not found.
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	char *found = NULL;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			found = &(*(s + i));
			break;
		}

		i++;
	}

	return (found);
}
