#include "main.h"

/**
 * num_builtin_commands - Get the number of builtin commands.
 *
 * Return: The number of builtin commands.
 */
int num_builtin_commands(void)
{
	char *builtin_commands[] = {"cd", "exit"};

	return (sizeof(builtin_commands) / sizeof(char *));
}

/**
 * change_directory - Builtin command to change directory.
 *
 * @args: List of arguments.
 * Return: Always 1.
 */
int change_directory(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "./shell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("./shell");
		}
	}
	return (1);
}

/**
 * exit_shell - Runs the builtin command exit.
 *
 * @args: List of arguments (not considered).
 * Return: Always 0.
 */
int exit_shell(char **args)
{
	(void)args;

	return (0);
}

/**
 * launch_process - Starts a program.
 *
 * @args: Null-terminated list of arguments.
 * Return: Always 1.
 */
int launch_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("./shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("./shell");
	}
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			waitpid(pid, &status, WUNTRACED);
		}
	}
	return (1);
}

/**
 * execute_command - Executes builtins or launches a process.
 *
 * @args: Null-terminated list of arguments.
 * Return: Returns 1 if the shell continues and 0 if it should terminate.
 */
int execute_command(char **args)
{
	char *builtin_commands[] = {"cd", "exit"};
	int command_index = -1;

	int (*builtin_functions[])(char **) = {&change_directory, &exit_shell};
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < num_builtin_commands(); i++)
	{
		if (strcmp(args[0], builtin_commands[i]) == 0)
		{
			command_index = i;
			break;
		}
	}

return ((command_index != -1) ? (*builtin_functions[command_index])(args) :
	launch_process(args));
}
