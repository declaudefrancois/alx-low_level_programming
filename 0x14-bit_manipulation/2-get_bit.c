/**
 * get_bit - Gets the value of a bit at a given index
 *           of a given number.
 *
 * @n: The number.
 * @index: The index.
 *
 * Return: A integer with the bit at index `index` from number.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/**
	 * 8 bytes for one unsigned long int
	 * (max bit index).
	 */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return (((1 << index) & n) >> index);
}
