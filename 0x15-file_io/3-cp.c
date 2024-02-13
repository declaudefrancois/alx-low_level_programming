#include "main.h"


/**
 * open_destination - Open the destination file and return the
 *                    file descriptor if success.
 *
 * @path: The path to the file to open.
 *
 * Return: The file descriptor.
 */
int open_destination(const char *path)
{
	int fd;

	fd = open(path,
			O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n",
				path);
		exit(99);
	}

	return (fd);
}


/**
 * open_source - Open the source file and return the
 *               file descriptor if success.
 *
 * @path: The path to the file to open.
 * Return: The file descriptor.
 */
int open_source(const char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n",
				path);
		exit(99);
	}

	return (fd);
}



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
	ssize_t readBytesCount, BUFF_SIZE = 1024 * sizeof(char);
	char *buffer = malloc(BUFF_SIZE);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdSource = open_source(argv[1]);
	fdDestination = open_destination(argv[2]);
	readBytesCount = read(fdSource, buffer, BUFF_SIZE);

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
		readBytesCount = read(fdSource, buffer, BUFF_SIZE);
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
