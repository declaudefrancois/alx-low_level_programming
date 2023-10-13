/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 *
 * @n: The number to set the bit for.
 * @index: The index of the bit to set.
 *
 *
 * Return: 1 on success or -1 on failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long mask;

	if (!*n)
		return (-1);

	mask = (1 << index);
	*n ^= mask;
	return (1);
}
