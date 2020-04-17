#include "header.h"

/**
 * main - main function for simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *input;
	size_t bufsize = 32;
	char **parsed_input;
	char *program;
	char *pathVar;
	char *pathJoinedProgram;

	while (1)
	{
		input = prompt_for_input(bufsize);
		parsed_input = split(input, " ");
		if (parsed_input == NULL)
		{
			continue;
		}
		program = parsed_input[0];
		pathVar = getEnvVar(env, "PATH");
		pathJoinedProgram = path_for_program(pathVar, program);
		if (pathJoinedProgram == NULL)
		{
			perror("Unable to find program");
			continue;
		}

		execute(av);

		free_str_arr(parsed_input);
		free(pathJoinedProgram);
	}
	return (0);
}
