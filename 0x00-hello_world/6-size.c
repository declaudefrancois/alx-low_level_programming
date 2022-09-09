#include <stdio.h>

/**
 * main - netry point
 *
 * Return: 0
 */
int main(void)
{
	char c = 'c';
	int v_int = 1;
	long int v_long_int = 1000000;
	long long int v_long_long_int = 9223372036854775807;
	float v_float = 4.5;

	printf("Size of a char: %ld byte(s)\n", sizeof(c));
	printf("Size of an int: %ld byte(s)\n", sizeof(v_int));
	printf("Size of a long int: %ld byte(s)\n", sizeof(v_long_int));
	printf("Size of a long long int: %ld byte(s)\n", sizeof(v_long_long_int));
	printf("Size of a float: %ld byte(s)\n", sizeof(v_float));

	return (0);
}

