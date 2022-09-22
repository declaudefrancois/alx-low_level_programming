/**
 * _strcat - concatenate two strng
 * @dest: the dest string
 * @src: the source string
 *
 * Return: char * a pointer to a string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	/* get the index of the null byte of dest */
	while (dest[i] != '\0')
		i++;

	/* copy src in dest starting in from i*/
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	*(dest + i) = '\0';

	return (dest);

}
