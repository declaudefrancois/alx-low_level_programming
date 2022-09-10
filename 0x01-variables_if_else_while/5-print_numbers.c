#include <stdio.h>

/**
 * main - main entry point
 *
 * Return: 0
 */
int main(void)
{
	int i = 0;

	do {
		printf("%d", i);
		i++;
	} while (i < 10);

	printf("\n");

	return (0);
}

