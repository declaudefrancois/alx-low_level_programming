#include "main.h"

/**
 * _calloc - calloc implementation.
 * Memory alllcation for an aaray.
 *
 * @nmemb: number of element that
 * the array will contain.
 * @size: size in bits.
 *
 * Return: a pointerto the allocated
 * memory or NULL if fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	return (p);
}
