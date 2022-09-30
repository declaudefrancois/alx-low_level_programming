#include <unistd.h>

int _putchar(char c);

/**
 * main - prints the number of args.
 * @argc: number of arguments.
 * @argv: arguments array.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	_putchar(argc + '0');
	_putchar('\n');

	(void) argv;
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
