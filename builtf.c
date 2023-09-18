#include "main.h"

/**
 * custom_myexit - Exits the shell.
 * @info: Pointer to the custom_info_t struct containing potential arguments.
 *
 * Return: Exits with a given exit status (0) if info->argv[0] != "exit".
 */
int custom_myexit(custom_info_t *info)
{
	int exit_status;

	exit_status = info->argv[1] ? (custom_erratoi(info->argv[1]) == -1 ? (
info->status = 2, print_error(info, "Illegal number: "),
_eputs(info->argv[1]), _eputchar('\n'), 1
) : (info->err_num = custom_erratoi(info->argv[1]), -2)) :
	(info->err_num = -1, -2);

	return (exit_status);
}

/**
 * custom_mycd - Changes the current directory of the process.
 * @info: Pointer to the custom_info_t
 * struct containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_mycd(custom_info_t *info)
{
	char *current_directory, *new_directory, buffer[1024];
	int chdir_result;

	current_directory = getcwd(buffer, 1024);
	if (!current_directory)
		_puts("TODO: Handle getcwd failure here\n");

	chdir_result = !info->argv[1] ? (
		new_directory = custom_getenv(info, "HOME="),
		!new_directory ? ( chdir(
(new_directory = custom_getenv(info, "PWD=")) ? new_directory : "/"
			)) : chdir(new_directory)
	) : custom_strcmp(info->argv[1], "-") == 0 ? (
		!custom_getenv(info, "OLDPWD=") ? (
			_puts(current_directory),
			_putchar('\n'),
			1
		) : (_puts(custom_getenv(info, "OLDPWD=")), _putchar('\n'), chdir(
				(new_directory = custom_getenv(info, "OLDPWD=")) ? new_directory : "/"
			))
	) : chdir(info->argv[1]);

	if (chdir_result == -1)
		print_error(info, "can't cd to "), _eputs(info->argv[1]), _eputchar('\n');
	else
		custom_setenv(info, "OLDPWD", custom_getenv(info, "PWD=")),
			custom_setenv(info, "PWD", getcwd(buffer, 1024));

	return (0);
}

/**
 * custom_myhelp - Display help information.
 * @info: Pointer to the custom_info_t struct containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_myhelp(custom_info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("The 'help' command is not yet implemented.\n");
	if (0)
		_puts(*arg_array); /* Temporary unused variable workaround */

	return (0);
}
