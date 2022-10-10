#include "dog.h"

/**
 * init_dog - Initializes a variable of type
 * struct dog.
 * @d: a pointer to the variable to initialze.
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
