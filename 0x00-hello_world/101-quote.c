#include <unistd.h>
#include <sys/syscall.h>

/**
 * main - Entry point
 *
 * Return: 1
 */
int main(void)
{
	char part1[] = "and that piece of art is useful\"";
	char part2[] = " - Dora Korpar, 2015-10-19\n";

	write(1, part1, 32);
	write(1, part2, 27);
	return (1);
}

