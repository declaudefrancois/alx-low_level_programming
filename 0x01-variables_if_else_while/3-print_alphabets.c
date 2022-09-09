#include <stdio.h>
#include <ctype.h>
/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int i;
	int j;

	for (i = 0; i < 26; i++)
		putchar(alphabet[i]);

	for (j = 0; j < 26; j++)
		putchar(toupper(alphabet[j]));

	putchar('\n');

	return (0);
}

