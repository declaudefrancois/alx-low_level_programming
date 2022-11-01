#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 * it to the POSIX standard output.
 * @filename: The file path.
 * @letters: The numbers of letters to read.
 *
 * Return: The actual number of letters it could
 * read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int readCount = 0;
	int writeCount = 0;
	int bufSize = letters * sizeof(char);
	char *buffer = malloc(bufSize);
	int fd;

	if (filename == NULL || buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	readCount = read(fd, buffer, letters);
	writeCount = write(1, buffer, readCount);

	if (readCount == -1 || writeCount == -1 ||
	    readCount != writeCount)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);

	return (readCount);
}

