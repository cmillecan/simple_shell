# Simple Shell

## Project Overview
This is the final project for the first trimester at Holberton School. We created a simple shell using the C programming language.

## Program Requirements
* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
* All your files should end with a new line
* A `README.md file`, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

## Installation
To clone this respository, type
```
git clone https://github.com/cmillecan/simple_shell.git
```
To compile, use the following command and flags
```
gcc -Wall -Werror -Wextra and -pedantic *.c -o hsh
```
# Respository Contents
Simple Shell files:

| **File** | **Description** |
|----------|-----------------|
| header.h | Header file containing function prototypes and standard C library header files |
| main.c | Program entry point - int main(void) |
| helpers.c | Contains str_concat, getEnv, free_str_array, and join functions |
| helpers2.c | Contains split, strdup, and strcmp functions |
| helpers3.c | Contains execute, prompt_for_input, and path_for_program functions |
| man_1_simple_shell | Man Page for Simple Shell |

## Authors
* [**Andrew Cox**](https://github.com/AndrewC7)
* [**Samuel Messenger**](https://github.com/Sammessenger)
* [**Constance Millecan**](https://github.com/cmillecan)
