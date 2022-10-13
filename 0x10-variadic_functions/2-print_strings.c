#include "variadic_functions.h"

/**
 * print_strings - prints strings received as arguments,
 * followed by a new line.
 * @separator: the char separator to use.
 * @n: the numbers of optionals args to
 * consider.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *s;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, char*);
		if (s == NULL)
			printf("%s", "(nil)");
		else
			printf("%s", s);

		if (i != n - 1 && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}

