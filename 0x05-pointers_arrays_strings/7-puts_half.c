#include "main.h"
int _strlen(char *s);

/**
 * puts_half - puts the half of a string
 * @str: the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int s_length = _strlen(str);
	int i, n;

	if (s_length % 2 == 0)
		n = s_length / 2;
	else
		n = (s_length - 1) / 2;

	i = s_length - n;

	while (i < s_length)
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
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
