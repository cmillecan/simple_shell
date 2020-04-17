#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
char **split(char *str, const char *delim);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *getEnvVar(char **env, char *key);
void free_str_arr(char **str_arr);
char *join(char *str1, char *delim, char *str2);
char *str_concat(char *s1, char *s2);
void execute(char **argv);
char *prompt_for_input(size_t bufsize);
char *path_for_program(char *pathVar, char *program);

#endif
