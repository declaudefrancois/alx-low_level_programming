#include "main.h"
int _strlen(char *s);

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int s_length = _strlen(s);
	int i = 0, j;
	char tmp;

	while (i < s_length)
	{
		j = s_length - (i + 1);
		if (i > j)
			break;

		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		i++;
	}
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
