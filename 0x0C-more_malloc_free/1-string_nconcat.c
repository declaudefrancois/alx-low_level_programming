#include "main.h"
int _strlen(char *s);

/**
 * string_nconcat -  concatenates two strings, taking only
 * n chars of the second string or the entire sting if
 * n greater than second string length.
 *
 * @s1: the first string.
 * @s2: the second string.
 * @n: the number of s2 chars to cpoy.
 *
 * Return: the resulting string
 * or NULL if error.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int size = 0, i = 0, j = 0;
	char *s;

	if (s2 != NULL)
		size += _strlen(s2);
	size = size > n ? n : size;

	if (s1 != NULL)
		size += _strlen(s1);

	s = (char *) malloc(size + 1);
	if (s == NULL)
		return (NULL);

	while (s1 != NULL && *(s1 + i) != '\0')
	{
		*(s + i) = *(s1 + i);
		i++;
	}

	while (s2 != NULL &&
	       *(s2 + j) != '\0' &&
	       j < n)
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
