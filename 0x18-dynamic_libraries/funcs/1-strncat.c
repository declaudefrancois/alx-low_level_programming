/**
 * _strncat - concatenate n char of src with dest
 * @dest: the destination string
 * @src: the source string
 * @n: the number of char from src to concatenate with dest
 *
 * Return: a Pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{

	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
