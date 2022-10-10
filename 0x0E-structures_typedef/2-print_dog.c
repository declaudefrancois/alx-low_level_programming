#include "dog.h"

/**
 * print_dog - print a dog
 * @d: a pointer to a struct dog to print.
 *
 * Return: void.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
}
