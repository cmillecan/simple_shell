#include "header.h"

/**
 * execute - executes the program
 * @argv: arguments
 * Return: void
 */
void execute(char **argv)
{
	pid_t pid;
	int status;
	char *env_args[] = { (char *)0 };

	pid = fork();
	if (pid < 0)
	{
		perror("Unable to fork\n");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(*argv, argv, env_args) < 0)
		{
			perror("Execution failed");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
