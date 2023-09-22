#include "main.h"

/**
 * main - entry point
 *
 * @argc: first parameter
 * @argv: second parameter
 * @envp: third parameter
 *
 * Return: 0 if success
 */
int main(int argc, char **argv, char **envp)
{
	char *input_line = NULL, **input_tokens = NULL, **path_tokens = NULL, *executable_path = NULL;

	(void)argv;
	(void)argc;
	while (1)
	{
		display_prompt();
		input_line = get_input_line();
		if (input_line == NULL)
			return (0);
		if (input_line)
		{
			input_tokens = parse_input(input_line);
			if (input_tokens == NULL)
				return (0);
			if (compare_strings(input_tokens[0], "exit", 4) == 0)
			{
				free(input_line);
				free(input_tokens);
				exit(EXIT_SUCCESS);
			}
			if (compare_strings(input_tokens[0], "env", 3) == 0)
				print_environment(envp);
			else
			{
				int path_type = is_valid_path(input_tokens[0]);
				executable_path = input_tokens[0];
				if (path_type == 0)
				{
					path_tokens = parse_path(envp);
					executable_path = search_file(input_tokens[0], path_tokens);
				}
				if (path_type == 1 || (path_type == 0 && compare_strings(executable_path, "0", 1) == 0))
					puts("command not found");
				else if (path_type == 2 || (path_type == 0 && compare_strings(executable_path, "0", 1) != 0))
					execute_command(input_tokens, executable_path, envp);
				free(input_line);
				free(input_tokens);
			}
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
