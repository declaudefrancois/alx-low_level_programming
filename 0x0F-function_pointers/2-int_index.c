#include "function_pointers.h"

/**
 * int_index - function that searches for an integer
 * in a array.
 * @array: the array look in.
 * @size: array size.
 * @cmp: a pointer to the function to be used to compare values
 *
 * Return: returns the index of the first element
 * for which the cmp function does not return 0
 * or -1 if fails.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size < 0 ||
	    array == NULL ||
	    cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
