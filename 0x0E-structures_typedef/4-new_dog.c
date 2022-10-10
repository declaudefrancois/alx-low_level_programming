#include "dog.h"

int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/**
 * new_dog -  creates a new dog
 * using typedef dog_t
 * @name: the dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: A variable of type dog_t
 * or NULL if fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;

	if (name == NULL || owner == NULL)
		return (NULL);

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
		return (NULL);

	newDog->name = malloc((_strlen(name) + 1) * sizeof(char));
	if (newDog->name == NULL)
	{
		free(newDog);
		return (NULL);
	}

	newDog->owner = malloc((_strlen(owner) + 1) * sizeof(char));
	if (newDog->owner == NULL)
	{
		free(newDog->name);
		free(newDog);
		return (NULL);
	}

	newDog->age = age;
	newDog->name = _strcpy(newDog->name, name);
	newDog->owner = _strcpy(newDog->owner, owner);

	return (newDog);
}

/**
 * _strlen - string length
 * @s: the string to get the length
 *
 * Return: int the string's length
 */
int _strlen(char *s)
{
	int i = 0, size = 0;

	while (s[i] != '\0')
	{
		size++;
		i++;
	}

	return (size);
}

/**
 * _strcpy - copy a string
 * @dest: the destination
 * @src: the string to be copied
 *
 * Return: a pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (1)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			break;

		i++;
	}

	return (dest);
}
