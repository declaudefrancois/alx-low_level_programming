#include <stdlib.h>
int _strlen(char *s);

/**
 * str_concat -  concatenates two strings.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: the resulting string
 * or NULL if error.
 */
char *str_concat(char *s1, char *s2)
{
	int size = 0, i = 0, j = 0;
	char *s;

	if (s1 != NULL)
		size += _strlen(s1);

	if (s2 != NULL)
		size += _strlen(s2);

	s = (char *) malloc(size + 1);
	if (s == NULL)
		return (NULL);

	while (s1 != NULL && *(s1 + i) != '\0')
	{
		*(s + i) = *(s1 + i);
		i++;
	}

	while (s2 != NULL && *(s2 + j) != '\0')
	{
		*(s + i) = *(s2 + j);
		j++;
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
