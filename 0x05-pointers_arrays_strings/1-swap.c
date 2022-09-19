/**
 * swap_int - swap two int
 * @a: the first int
 * @b: the second int
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
