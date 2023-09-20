#include "main.h"

/**
 * custom_exit_main - Exits the shell.
 * @info: Structure containing potential arguments.
 *
 * Return: Exits with a given exit status (0) if info->argv[0] != "exit".
 */
int custom_exit_main(custom_info_t *info)
{
	int exit_check;

	if (info->argv[1])
	{
		exit_check = custom_error_atoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			custom_print_error(info, "Illegal number: ");
			custom_puts(info->argv[1]);
			custom_putchar('\n');
			return (1);
		}
		info->err_num = custom_error_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * custom_change_directory - Changes the current directory of the process.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_change_directory(custom_info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		custom_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = custom_get_environment(info, "HOME=");
		if (!dir)
		chdir_ret = chdir((dir = custom_get_environment(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (custom_strcmp(info->argv[1], "-") == 0)
	{
		if (!custom_get_environment(info, "OLDPWD="))
		{
			custom_puts(s);
			custom_putchar('\n');
			return (1);
		}
	custom_puts(custom_get_environment(info, "OLDPWD=")), custom_putchar('\n');
chdir_ret = chdir((dir = custom_get_environment(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		custom_print_error(info, "can't cd to ");
		custom_puts(info->argv[1]), custom_putchar('\n');
	}
	else
	{
custom_set_custom_environment
	(info, "OLDPWD", custom_get_environment(info, "PWD="));
custom_set_custom_environment(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * custom_help - Prints help message (not yet implemented).
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_help(custom_info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	custom_puts("help call works. Function not yet implemented \n");
	if (0)
		custom_puts(*arg_array);
	return (0);
}
