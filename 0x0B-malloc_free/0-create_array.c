#include <stdlib.h>

/**
 * create_array - create an array of char
 * of size size and initializes its elements
 * with a char c.
 *
 * @size: the array size
 * @c: the char to use
 *
 * Return: A pointer to the resulting array
 * or NULL if error.
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);

	s = (char *) malloc(size);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(s + i) = c;

	return (s);
}
