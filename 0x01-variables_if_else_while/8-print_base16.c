#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	int n = 48;
	int l = 97;

	do {
		putchar(n);
		n++;
	} while (n <= 57);

	do {
		putchar(l);
		l++;
	} while (l <= 102);

	putchar('\n');

	return (0);
}

