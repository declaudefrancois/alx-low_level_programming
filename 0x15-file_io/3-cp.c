#include "main.h"
int _strlen(char *s);
void closeFd(int fd);

/**
 * main - Copies the content of a file to another file.
 * @argc: Arguments count.
 * @argv: Arguemnts values.
 *
 * Return: Alaways 0.
 */
int  main(int argc, char **argv)
{
	int fdSource, fdDestination;
	int readBytesCount;
	char *buffer = malloc(1024 * sizeof(buffer));

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdSource = open(argv[1], O_RDONLY);
	if (fdSource == -1)
	{
		dprintf(STDERR_FILENO,
		      "Error: Can't read from file %s\n",
		      argv[1]);
		exit(98);
	}

	fdDestination = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 664);
	if (fdDestination == -1)
	{
		closeFd(fdSource);
		dprintf(STDERR_FILENO,
		      "Error: Can't write to %s\n",
		      argv[2]);
		exit(99);
	}

	readBytesCount = read(fdSource, buffer, 1024);
	if (readBytesCount == -1)
	{
		closeFd(fdSource);
		closeFd(fdDestination);
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n",
			argv[1]);
		exit(98);
	}

	while (readBytesCount > 0)
	{
		write(fdDestination, buffer, readBytesCount);
		readBytesCount = read(fdSource, buffer, 1024);
	}

	closeFd(fdSource);
	closeFd(fdDestination);

	return (EXIT_SUCCESS);
}

/**
 * closeFd - Close a file descriptor.
 * @fd: The file descirptor to close.
 */
void closeFd(int fd)
{
	int res = close(fd);

	if (res == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * _strlen - string length
 * @s: the string to get the length
 *
 * Return: int the string's length
 */
int _strlen(char *s)
{
	int size = 0;

	while (s[size] != '\0')
		size++;

	return (size);
}
