#include "main.h"

/**
 * _realloc -  reallocates a memory block using malloc and free.
 * @ptr: the pointer to reallocate
 * @old_size: the old size of the pointer.
 * @new_size: the new size of the pointer.
 *
 * Return: The reallocated pointer or NULL
 * if fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);

	if (ptr == NULL)
		return (p);

	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);

	free(ptr);
	return (p);
}
