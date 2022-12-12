/**
 * _strcpy - copy a string
 * @dest: the destination
 * @src: the string to be copied
 *
 * Return: a pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (1)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			break;

		i++;
	}

	return (dest);
}
