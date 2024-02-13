#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
/**
 * _strlen - string length
 * @s: the string to get the length
 *
 * Return: int the string's length
 */
int _strlen(char *s);


/**
 * closeFd - Close a file descriptor.
 * @fd: The file descirptor to close.
 */
void closeFd(int fd);

#endif /* MAIN_H  */
