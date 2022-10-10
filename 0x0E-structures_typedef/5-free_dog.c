#include "dog.h"

/**
 * free_dog - frees memory used by a
 * dog_t variable.
 * @d: a pointer to the dog_t
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
