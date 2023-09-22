#include "main.h"

/**
 * get_input_line - read a line from the user
 *
 * Return: string
 */
char *get_input_line(void)
{
	/* Declare variables */
	char *input_line = NULL;
	size_t size = 0;
	int character, i = 0;

	size = 0;
	if (getline(&input_line, &size, stdin) == -1)
	{
		free(input_line);
		return (NULL);
	}
	i = 0;
	do

	{
		character = input_line[i];
		if (character == '\n')
		{
		input_line[i] = '\0';
		break;
		}
		if (character == EOF)
		{
		exit(EXIT_SUCCESS);
		}
		i++;
	} while (1);

	return (input_line);
}
