#include <unistd.h>

int _putchar(char c);

/**
 * main - a program that prints its name.
 * @argc: arguments count.
 * @argv: array arguments values.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *name = argv[0];
	int i = 0;

	while (name[i] != '\0')
	{
		_putchar(name[i]);
		i++;
	}

	(void) argc;
	_putchar('\n');

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
