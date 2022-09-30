#include <unistd.h>

int _putchar(char c);

/**
 * main - prints its arguments.
 * @argc: number of arguments.
 * @argv: arguments array.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, j;

	for (i = 0; i < argc; i++)
	{
		j = 0;
		while (*(argv[i] + j) != '\0')
		{
			_putchar(*(argv[i] + j));
			j++;
		}

		_putchar('\n');
	}

	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
