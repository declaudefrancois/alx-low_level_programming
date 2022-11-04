#include "main.h"
int _strlen(char *s);

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The content to appent in the file.
 *
 * Return: Int, 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int writtenBytesCount;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	writtenBytesCount = write(fd, text_content, _strlen(text_content));
	if (writtenBytesCount == -1)
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
