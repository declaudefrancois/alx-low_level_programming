#include <unistd.h>
#include <sys/syscall.h>

/**
 * main - Entry point
 *
 * Return: 1
 */
int main(void)
{
	const char text[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	syscall(SYS_write, 1, text, sizeof(text));
	return (1);
}

