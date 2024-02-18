#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */
int largest_number(int a, int b, int c)
{
	int largest;

	if (a > b)
		largest = a > c ? a : c;
	else if (a > c)
		largest = a > b ? a : b;
	else
		largest = b > c ? b : c;

	return (largest);
}
