#include <stdio.h>
#include <stdlib.h>

/**
 * main - add numbers.
 * @argc: args count
 * @argv: array of args
 *
 * Return: 0 if success otherwise 1 on error.
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i, j;

	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (*(argv[i] + j) != '\0')
		{
			if (!(*(argv[i] + j) >= '0' &&
			    *(argv[i] + j) <= '9'))
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
