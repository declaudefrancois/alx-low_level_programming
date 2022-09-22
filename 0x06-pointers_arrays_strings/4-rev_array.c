/**
 * reverse_array - reserve elements of an int array
 * @a: the array
 * @n: the length of the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i = 0, j;
	int tmp;

	for (i = 0; i < n; i++)
	{
		j = n - (i + 1);
		if (i > j)
			break;

		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;

		i++;
	}
}
