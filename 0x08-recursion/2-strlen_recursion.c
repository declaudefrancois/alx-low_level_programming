/**
 * _strlen_recursion - lenght of a string with recusrion
 * @s: the string.
 *
 * Return: int , thestring length.
 */
int _strlen_recursion(char *s)
{
	int l = 0;

	if (*s != '\0')
	{
		return (1 + _strlen_recursion((s + 1)));
		l++;
	}

	return (0);
}
