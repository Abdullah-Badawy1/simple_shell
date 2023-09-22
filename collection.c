#include "main.h"

/**
 * display_prompt - Display the shell prompt.
 *
 * Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, " $ ", 4);
	}
}

/**
 * is_valid_path - Check if the command contains a '/' character.
 *
 * @command: The command to check.
 *
 * Return:
 * - 1 if the command is a valid path.
 * - 2 if the command is a valid path and exists.
 * - 0 otherwise.
 */
int is_valid_path(char *command)
{
	int i = 0;
	int fd;
	int result = 0;

	do

	{
		switch (command[i])
		{
			case '/':
				fd = access(command, F_OK);
				result = (fd == -1) ? 1 : 2;
				break;
		}
		i++;
	} while (command[i] != '\0');

	return (result);
}

/**
 * is_empty_input - Check if the input line is empty.
 *
 * @line: Input line.
 *
 * Return:
 * - 1 if the input is empty.
 * - 0 otherwise.
 */
int is_empty_input(char *line)
{
	int i = 0;
	int space_count = 0;
	int length = string_length(line);
	int result = 0;

	do

	{
		switch (line[i])
		{
			case '\n':
				result = 1;
				break;
			case ' ':
				space_count++;
				break;
		}
		if (space_count == length)
		{
			result = 1;
		}
		i++;
	} while (line[i] != '\0');

	return (result);
}

/**
 * remove_newline_character - Remove newline character from a string.
 *
 * @str: The string.
 *
 * Return: void
 */
void remove_newline_character(char *str)
{
	int i = 0;

	do

	{
		if (str[i] == '\n')
			break;
		i++;
	} while (str[i] != '\0');

	str[i] = '\0';
}
