#include "main.h"

/**
 * custom_myenv - Prints the current environment variables.
 * @info: Pointer to the custom_info_t struct containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_myenv(custom_info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * custom_getenv - Gets the value of an environment variable.
 * @info: Pointer to the custom_info_t struct.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *custom_getenv(custom_info_t *info, const char *name)
{
	list_t *env_node = info->env;
	char *value;

	while (env_node)
	{
		value = starts_with(env_node->str, name);
		return ((value && *value) ? value : NULL);
		env_node = env_node->next;
	}
	return (NULL);
}

/**
 * custom_mysetenv - Initializes a new environment variable
 *                   or modifies an existing one.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: Always 0.
 */
int custom_mysetenv(custom_info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Usage: mysetenv VARIABLE VALUE\n");
		return (1);
	}

	return ((custom_setenv(info, info->argv[1], info->argv[2])) ? 0 : 1);
}

/**
 * custom_myunsetenv - Removes an environment variable.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: Always 0.
 */
int custom_myunsetenv(custom_info_t *info)
{
	int i = 1;

	if (info->argc == 1)
	{
		_eputs("Usage: myunsetenv VARIABLE [VARIABLE ...]\n");
		return (1);
	}

	do

	{
		custom_unsetenv(info, info->argv[i]);
		i++;
	} while (info->argv[i]);

	return (0);
}

/**
 * custom_populate_env_list - Populates the environment linked list
 *                           with the current environment variables.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: Always 0.
 */
int custom_populate_env_list(custom_info_t *info)
{
	list_t *env_list = NULL;
	size_t i = 0;

	do

	{
		add_node_end(&env_list, environ[i], 0);
		i++;
	} while (environ[i]);

	info->env = env_list;
	return (0);
}
