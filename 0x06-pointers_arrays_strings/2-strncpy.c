/**
 * _strncpy - copy n char of src to dest
 * @dest: pointer to dest string
 * @src: pointer to src string
 * @n: number of char from src to copy
 *
 * Return: pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
