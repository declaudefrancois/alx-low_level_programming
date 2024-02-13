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
	ssize_t readCount = 0,  writeCount = 0;
	char *text = malloc(letters * sizeof(char));
	int fd;

	if (filename == NULL || text == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(text);
		return (0);
	}

	readCount = read(fd, text, letters);
	writeCount = write(STDOUT_FILENO, text, readCount);

	if (readCount == -1 || writeCount == -1 ||
	    readCount != writeCount)
	{
		free(text);
		return (0);
	}

	free(text);
	close(fd);

	return (readCount);
}

