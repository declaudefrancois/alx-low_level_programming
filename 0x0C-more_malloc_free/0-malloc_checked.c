#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc.
 * @b: the memory space (bits) to allocate.
 *
 * Return: A void pointer to the allocated
 * memory or exit with status 98 if fails.
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);
	return (p);
}
