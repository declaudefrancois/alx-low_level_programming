/**
 * set_bit - ets the value of a bit to 1 at a given index.
 *
 * @n: The number to set the bit for.
 * @index: The index of the bit to set.
 *
 * Return: The number with the bit at index `index` set to 1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (!n || index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask = 1 << index;
	*n |= mask;
	return (1);
}
