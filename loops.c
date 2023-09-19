#include "main.h"

/**
 * custom_shell - Main shell loop
 * @info: Pointer to the parameter and return info struct
 * @av: The argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int custom_shell(custom_info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	do

	{
		custom_clear_info(info);
		if (custom_interactive(info))
			custom_puts("$ ");
		custom_putchar(BUF_FLUSH);
		r = custom_get_input(info);

		if (r != -1)
		{
			custom_set_info(info, av);
			builtin_ret = custom_find_builtin(info);
			if (builtin_ret == -1)
				custom_find_command(info);
		}
		else if (custom_interactive(info))
			custom_putchar('\n');
		custom_free_info(info, 0);
	} while (r != -1 && builtin_ret != -2);

	custom_write_history(info);
	custom_free_info(info, 1);

	if (!custom_interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}

	return (builtin_ret);
}

/**
 * custom_find_builtin - Finds a builtin command
 * @info: Pointer to the parameter and return info struct
 *
 * Return: -1 if builtin not found,
 *         0 if builtin executed successfully,
 *         1 if builtin found but not successful,
 *         -2 if builtin signals exit()
 */
int custom_find_builtin(custom_info_t *info)
{
	int i, built_in_ret = -1;
	custom_builtin_table builtintbl[] = {
		{"exit", custom_exit_main},
		{"env", custom_custom_environment},
		{"help", custom_help},
		{"history", custom_history},
		{"setenv", custom_set_environment},
		{"unsetenv", custom_unset_environment},
		{"cd", custom_change_directory},
		{"alias", custom_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (custom_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	}

	return (built_in_ret);
}

/**
 * custom_find_command - Finds a command in PATH
 * @info: Pointer to the parameter and return info struct
 *
 * Return: void
 */
void custom_find_command(custom_info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
	{
		if (!custom_is_delimiter(info->arg[i], " \t\n"))
		{
			k++;
		}
	}
	if (!k)
	{
		return;
	}
path = custom_find_path
	(info, custom_get_environment(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		custom_fork_command(info);
	}
	else
	{
		if ((custom_interactive(info) || custom_get_environment(info, "PATH=")
		|| info->argv[0][0] == '/') && custom_is_command(info, info->argv[0]))
		{
			custom_fork_command(info);
		}
		else if (*(info->arg) != '\n')
		{
		info->status = 127;
		custom_print_error(info, "not found\n");
		}
	}
}

/**
 * custom_fork_command - Forks an exec thread to run cmd
 * @info: Pointer to the parameter and return info struct
 *
 * Return: void
 */
void custom_fork_command(custom_info_t *info)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(info->path, info->argv,
			custom_get_environ(info)) == -1)
		{
			custom_free_info(info, 1);

			if (errno == EACCES)
			{
				exit(126);
			}

			exit(1);
		}
	}
	else
	{
		wait(&(info->status));

		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
			{
			custom_print_error(info, "Permission denied\n");
			}
		}
	}
}
