#include "main.h"

/**
 * create_file - A function that creates a file.
 * @filename: The file name.
 * @text_content: The content of the file.
 *
 * Return: Int , 1 on success , -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_count;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	write_count = write(fd, text_content, _strlen(text_content));
	if (write_count == -1)
		return (-1);

	return (1);
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
