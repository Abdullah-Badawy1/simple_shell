#include "main.h"

/**
 * execute_command - Execute a command.
 *
 * @arguments: Array of command arguments.
 * @path: Path to the executable.
 * @envp: Environment variable array.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **arguments, char *path, char **envp)
{
	int status, exec_result;
	pid_t pid;

	switch ((pid = fork()))
	{
		case -1:
			perror("fork");
			return (-1);
		case 0:
			exec_result = execve(path, arguments, envp);
			if (exec_result == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
			break;
		default:
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				return (-1);
			}
			break;
	}

	return (0);
}
