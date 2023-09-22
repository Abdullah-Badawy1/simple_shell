#include "main.h"

/**
 * read_input_line - Read a line from the user.
 *
 * Return: A string containing the input line.
 */
char *read_input_line(void)
{
	char *input_line = NULL;
	size_t size;

	size = 0;

	if (getline(&input_line, &size, stdin) == -1)
	{
		free(input_line);
		exit(EXIT_SUCCESS);
	}
	return (input_line);
}
