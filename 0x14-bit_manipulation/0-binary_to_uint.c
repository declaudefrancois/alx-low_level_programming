#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int in decimal.
 *
 * @b: The binary number to convert.
 *
 * Return: The converted number.
 *
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0,
		     power = 0,
		     j = 0,
		     power2;
	int len = 0;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
	{
		if (b[len] != '1' && b[len] != '0')
			return (0);
		len++;
	}
	--len;

	while (len >= 0 && b[len])
	{
		if (b[len] == '1')
		{
			if (power == 0)
				num++;
			else
			{
				power2 = 1;
				for (j = 1 ; j <= power; j++)
					power2 *= 2;
				num += power2;
			}
		}

		len--;
		power++;
	}

	return (num);
}
