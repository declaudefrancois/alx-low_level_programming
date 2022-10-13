#include "function_pointers.h"

/**
 * print_name - print a name by passing
 * the name to the function pointer both
 * received as args.
 * @name: the name to print.
 * @f: a function pointer.
 *
 * Return: void.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		(*f)(name);
}
