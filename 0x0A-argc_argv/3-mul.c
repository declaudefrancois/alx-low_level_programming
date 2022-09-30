#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiply two
 * passed in argv.
 *
 * @argc: the number of args
 * @argv: array of args.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}

