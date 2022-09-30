#include <stddef.h>

/**
 * _strstr - locates a substring.
 * @haystack: the string to look inside.
 * @needle: the substring to lok for.
 *
 * Return: pointer to the beginning of the located substring
 * in haystack.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;
	char *found;

	while (haystack[i] != '\0')
	{
		j = 0;
		found = &(*(haystack + i));
		while (1)
		{
			if (haystack[i] != needle[j])
			{
				i++;
				break;
			}

			if (needle[j + 1] == '\0')
				return (found);

			i++;
			j++;
		}
	}

	return (NULL);
}
