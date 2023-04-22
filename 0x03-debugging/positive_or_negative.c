#include <stdio.h>

/**
 * main - Checks if i is > 0 or
 * < 0.
 *
 * @i: The number to test.
 */
void positive_or_negative(int i)
{
	if (i > 0)
		printf("%d is positive\n", i);
	else if (i < 0)
		printf("%d is negative\n", i);
	else
		printf("%d is zero\n", i);

}
