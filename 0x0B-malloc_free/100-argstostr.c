#include <stdlib.h>
int _strlen(char *s);

/**
 * argstostr - concatenates all the argument received by main.
 * @ac: argc from main
 * @av: array argv from main
 *
 * Return: A pointer to the resulting string.
 */
char *argstostr(int ac, char **av)
{
	char *s;
	int size = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		size += _strlen(*(av + i));

	s = (char *) malloc(sizeof(char) * (size + 1));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			s[k] = av[i][j];
			k++;
			j++;
		}
		s[k] = '\n';
		k++;
	}

	s[k] = '\0';
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
