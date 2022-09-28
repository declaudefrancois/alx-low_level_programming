/**
 * set_string - sets the value of a pointer to a char.
 * @s: a pointer to a pointer of string.
 * @to: a pointer to copy.
 *
 * Return: void.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
