#include "header.h"

/**
 * join - concatenates two strings and places a delimiter in between
 * @str1: first string
 * @delim: delimiter
 * @str2: second string
 * Return: returns a pointer to dest
 */
char *join(char *str1, char *delim, char *str2)
{
	char *result1;
	char *result2;

	result1 = str_concat(str1, delim);
	result2 = str_concat(result1, str2);

	free(result1);

	return (result2);
}

/**
 * str_concat - concatenates two strings
 * @s1: string one
 * @s2: strings two
 * Return: 0
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	int i;
	int j;
	int k;

	for (i = 0; s1 != NULL && s1[i] != '\0'; i++)
	{
	}
	for (j = 0; s2 != NULL && s2[j] != '\0'; j++)
	{
	}

	s3 = malloc(sizeof(char) * (i + j + 1));
	if (s3 == NULL)
	{
		return (NULL);
	}

	k = 0;
	for (i = 0; s1 != NULL && s1[i] != '\0'; i++)
	{
		s3[k] = s1[i];
		k++;
	}
	for (j = 0; s2 != NULL && s2[j] != '\0'; j++)
	{
		s3[k] = s2[j];
		k++;
	}
	s3[k] = '\0';

	return (s3);
}

/**
 * getEnvVar - gets the environment variable
 * @env: environment variable
 * @key: key
 * Return: char
 */
char *getEnvVar(char **env, char *key)
{
	size_t i;
	char **parsedEnvArr;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		parsedEnvArr = split(env[i], "=");

		if (_strcmp(parsedEnvArr[0], key) == 0)
			return (parsedEnvArr[1]);
		/* might need to free parsedEnvArr and all of it's elements here? */
	}

	return (NULL);
}

/**
 * free_str_arr - frees array
 * @str_arr: string array
 * Return: void
 */
void free_str_arr(char **str_arr)
{
	int i;

	for (i = 0; str_arr[i] != NULL; i++)
	{
		free(str_arr[i]);
	}
	free(str_arr);
}
