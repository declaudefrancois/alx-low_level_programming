#include <unistd.h>
#include <sys/syscall.h>

/**
 * main - Entry point
 *
 * Return: 1
 */
int main(void)
{
	const char part1[] = "and that piece of art is useful\"";
	const char part2[] = " - Dora Korpar, 2015-10-19\n";

	syscall(SYS_write, 1, part1, sizeof(part1));
	syscall(SYS_write, 1, part2, sizeof(part2));

	return (1);
}

