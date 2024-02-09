#include <limits.h>


/**
 * flip_bits - returns the number of bits to flip
 *             to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask;
	int i, word, bits_to_flip;

	word = CHAR_BIT * sizeof(n);
	mask = 1;
	bits_to_flip = 0;
	for (i = 0; i < word; i++)
	{
		if ((n & mask) != (m & mask))
			bits_to_flip++;
		mask <<= 1;
	}

	return (bits_to_flip);
}
