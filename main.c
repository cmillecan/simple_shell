#include "header.h"

/**
 * main - main function of simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment
 * Return: 0
 */
int main(__attribute__((unused)) int ac,
		__attribute__((unused)) char **av, char **env)
{
	char *input;
	char **stripped_input;
	size_t bufsize = 32;
	size_t char_count;
	char **parsed_input;
	int i, fd;
	char *program;
	char *pathVar;
	char **paths;
	char *pathJoinedProgram;

	while (1)
	{
		/* reads and allocates input */
		input = malloc(bufsize * sizeof(char));
		if (input == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}

		printf("$ ");

		char_count = getline(&input, &bufsize, stdin);
		stripped_input = split(input, "\n");
		free(input);
		if (stripped_input == NULL)
			continue;
		input = stripped_input[0];

		parsed_input = split(input, " ");
		if (parsed_input == NULL)
		{
			free_str_arr(stripped_input);
			continue;
		}
		program = parsed_input[0];
		/* get path variable from env */
		pathVar = getEnvVar(env, "PATH");
		/* then, split pathVar into it's different paths */
		paths = split(pathVar, ":");
		free(pathVar);
		for (i = 0; paths[i] != NULL; i++)
		{
			pathJoinedProgram = join(paths[i], "/", program);
			/* checks if pathJoinedProgram exists */
			fd = access(pathJoinedProgram, F_OK);
			if (fd != -1)
				break;
			free(pathJoinedProgram);
		}
		if (fd == -1)
		{
			perror("Unable to find program");
			free_str_arr(parsed_input);
			free_str_arr(paths);
			free(pathJoinedProgram);
			continue;
		}
		if (pathJoinedProgram != NULL)
		{
			execute(av);
		}
		free_str_arr(parsed_input);
		free_str_arr(paths);
		free(pathJoinedProgram);
	}
	return (0);
}

