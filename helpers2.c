#include "header.h"

/**
 * split - parses a string
 * @str: string
 * @delim: delimiter
 * Return: char
 */
char **split(char *str, const char *delim)
{
	char **result;
	char *piece;
	char *str_cpy;
	int count = 0;
	int i = 0;

	if (str == NULL)
		return (NULL);

	str_cpy = _strdup(str);

	piece = strtok(str, delim);
	while (piece != NULL)
	{
		piece = strtok(NULL, delim);
		count++;
	}

	result = malloc(sizeof(char *) * count + 1);
	if (result == NULL)
	{
		free(str_cpy);
		return (NULL);
	}

	piece = strtok(str_cpy, delim);
	while (piece != NULL)
	{
		result[i] = _strdup(piece);
		piece = strtok(NULL, delim);
		i++;
	}
	result[i] = NULL;

	free(str_cpy);

	return (result);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: string
 * Return: 0
 */
char *_strdup(char *str)
{
	int len;
	char *cpy;
	int i;

	len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*(str + len))
	{
		len++;
	}

	cpy = malloc(sizeof(char) * (len + 1));

	if (cpy == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		cpy[i] = str[i];
	}
	cpy[i] = '\0';

	return (cpy);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
