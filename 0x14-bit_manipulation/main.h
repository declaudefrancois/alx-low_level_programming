#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
/**
 * binary_to_uint - Converts a binary number to an `unsigned int`.
 *
 * @b: A pointer to a string of '0' and '1' chars.
 *
 * Return: The converted number of 0 if
 *         - there is one or more chars in the string b that is not 0 or 1.
 *         - b is NULL.
 */
unsigned int binary_to_uint(const char *b);

/**
 * str_len - Returns the string length.
 * @b: The string to get the length.
 *
 * Return: The string length.
 */
unsigned int str_len(const char *b);


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * print_binary - Prints the binary representation of number.
 * @n: The number to print.
 */
void print_binary(unsigned long int n);


/**
 * print_binary_recursive - Recursively prints the binary representation
 *                          of number.
 * @n: The number to print (must be greather than 0).
 */
void print_binary_recursive(unsigned long int n);


/**
 * get_bit - Gets the value of a bit at a given index
 *           of a given number.
 *
 * @n: The number.
 * @index: The index.
 *
 * Return: A integer with the bit at index `index` from number.
 */
int get_bit(unsigned long int n, unsigned int index);


/**
 * set_bit - ets the value of a bit to 1 at a given index.
 *
 * @n: The number to set the bit for.
 * @index: The index of the bit to set.
 *
 * Return: The number with the bit at index `index` set to 1.
 */
int set_bit(unsigned long int *n, unsigned int index);

int get_endianness(void);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int clear_bit(unsigned long int *n, unsigned int index);
#endif
