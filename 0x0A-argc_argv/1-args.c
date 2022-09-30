#include <stdio.h>

/**
 * main - prints the number of args.
 * @argc: number of arguments.
 * @argv: arguments array.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);

	(void) argv;
	return (0);
}

