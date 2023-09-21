#include "main.h"

/**
 * read_input_line - Get input from the user and read the line.
 *Return: The user input as a dynamically allocated string.
 */
char *read_input_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	switch (getline(&line, &bufsize, stdin))
	{
	case -1:
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("./shell: getline\n");
			exit(EXIT_FAILURE);
		}
		break;

	default:
		return (line);
	}
}

/**
 * split_input_line - Split line into tokens for execution.
 *
 * @line: Input line from the user.
 * Return: It returnis (token) NULL-terminated array of tokens.
 */
char **split_input_line(char *line)
{
	int bufsize = TOKEN_BUFFER_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "./shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
		bufsize += TOKEN_BUFFER_SIZE;
		tokens_backup = tokens;
		tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
			free(tokens_backup);
			fprintf(stderr, "./shell: allocation error\n");
			exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIMITERS);
	}

	tokens[position] = NULL;
	return (tokens);
}

/**
 * run_shell_loop - Print looped prompt
 * and wait for the user to enter input.
 */
void run_shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do

	{
		printf("cisfun>> ");
		line = read_input_line();
		args = split_input_line(line);
		status = execute_command(args);
		free(line);
		free(args);
	} while (status);
}
