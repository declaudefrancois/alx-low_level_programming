#include "main.h"

/**
 * print_alphabet - Print alphabet
 *
 * Return: 0
 */
void print_alphabet(void)
{
	int a = 97;

	while (a <= 122)
	{
		_putchar(a);
		a++;
	}

	_putchar(10);
}

