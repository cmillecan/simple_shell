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
/**
 * prompt_for_input - prompts, reads and allocates input
 * @bufsize: user input
 * Return: char
 */
char *prompt_for_input(size_t bufsize)
{
	char *input;
	char **stripped_input;

	input = malloc(bufsize * sizeof(char));
	if (input == NULL)
		return (NULL);

	printf("$ ");

	getline(&input, &bufsize, stdin);

	stripped_input = split(input, "\n");
	free(input);
	if (stripped_input == NULL)
		return (NULL);
	return (stripped_input[0]);
}

/**
 * path_for_program - finds existing path for program
 * @pathVar: path variable
 * @program: program
 * Return: existing path for program
 */
char *path_for_program(char *pathVar, char *program)
{
	char **paths;
	char *pathJoinedProgram;
	int i, fd;

	paths = split(pathVar, ":");
	free(pathVar);
	for (i = 0; paths[i] != NULL; i++)
	{
		pathJoinedProgram = join(paths[i], "/", program);
		fd = access(pathJoinedProgram, F_OK);
		if (fd != -1)
			break;
		free(pathJoinedProgram);
	}
	if (fd == -1)
	{
		free_str_arr(paths);
		free(pathJoinedProgram);
		return (NULL);
	}

	return (pathJoinedProgram);
}

