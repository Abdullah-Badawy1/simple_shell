#include "main.h"

/**
 * print_environment - Print environment variables.
 *
 * @envp: Environment variable array.
 *
 * Return: void
 */
void print_environment(char **envp)
{
	size_t run = 0;

	do

	{
		write(STDOUT_FILENO, envp[run], string_length(envp[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	} while (envp[run]);
}
