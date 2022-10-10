#ifndef DOG_H
#define DOG_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct dog - Dog structure
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 *
 *
 * Description: This structure represents a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H  */
