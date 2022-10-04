#include <stdlib.h>
int _strlen(char *s);

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: a pointer to the string to copy.
 *
 * Return: a pointer to the new string.
 */
char *_strdup(char *str)
{
	int i = 0;
	int str_ln;
	char *s;

	if (str == NULL)
		return (NULL);

	str_ln = _strlen(str);
	s = (char *) malloc((sizeof(char) * str_ln) + 1);
	if (s == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		*(s + i) = *(str + i);
		i++;
	}
	*(s + i) = '\0';

	return (s);
}


/**
 * _strlen - string length
 * @s: the string to get the length
 *
 * Return: int the string's length
 */
int _strlen(char *s)
{
	int i = 0, size = 0;

	while (s[i] != '\0')
	{
		size++;
		i++;
	}

	return (size);
}
