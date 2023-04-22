#include <unistd.h>
#include <string.h>
#include "main.h"

/**
* main - tests function that prints if integer is positive or negative
* Return: 0
*/

int main(void)
{
	int _stdout;
	int pipefd[2];
	char buff[100];

	_stdout = dup(STDOUT_FILENO);
	pipe(pipefd);
	dup2(STDOUT_FILENO, pipefd[1]);
	positive_or_negative(0);
	read(pipefd[0], buff, 50);
	printf("buff =>> \n%s <<<=\n", buff);
	if (strcmp(buff, "0 is zero\n") == 0)
	{
		printf("Test passed !\n");
		return (0);
	}
	else
	{
		printf("Test Failed !\ngot =>>>\n %s\n<<<=\n", buff);
		return (1);
	}
	dup2(_stdout, STDOUT_FILENO);
}
