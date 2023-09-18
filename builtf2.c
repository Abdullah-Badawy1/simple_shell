#include "main.h"

/**
 * custom_myhistory - Displays the history list, one command per line,
 *                   preceded by line numbers starting at 0.
 * @info: Pointer to the custom_info_t struct containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_myhistory(custom_info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * custom_unset_alias - Unsets an alias by removing it from the alias list.
 * @info: Pointer to the custom_info_t struct.
 * @alias: The string alias to unset.
 *
 * Return: Always 0 on success, 1 on error.
 */
int custom_unset_alias(custom_info_t *info, char *alias)
{
	char *equal_sign, c;
	int ret;

	equal_sign = custom_strchr(alias, '=');
	if (!equal_sign)
		return (1);
	c = *equal_sign;
	*equal_sign = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, alias, -1)));
	*equal_sign = c;
	return (ret);
}

/**
 * custom_set_alias - Sets an alias to a string.
 * @info: Pointer to the custom_info_t struct.
 * @alias: The string alias to set.
 *
 * Return: Always 0 on success, 1 on error.
 */
int custom_set_alias(custom_info_t *info, char *alias)
{
	char *equal_sign;

	equal_sign = custom_strchr(alias, '=');
	if (!equal_sign)
		return (1);
	if (!*++equal_sign)
		return (custom_unset_alias(info, alias));

	custom_unset_alias(info, alias);
	return (add_node_end(&(info->alias), alias, 0) == NULL);
}

/**
 * custom_print_alias - Prints an alias string.
 * @alias_node: The alias node to print.
 *
 * Return: Always 0 on success, 1 on error.
 */
int custom_print_alias(list_t *alias_node)
{
	char *equal_sign_pos = NULL, *alias_str = NULL;

	if (alias_node)
	{
		equal_sign_pos = custom_strchr(alias_node->str, '=');
		for (alias_str = alias_node->str; alias_str <= equal_sign_pos; alias_str++)
			_putchar(*alias_str);
		_putchar('\'');
		_puts(equal_sign_pos + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * custom_myalias - Mimics the alias builtin (man alias).
 * @info: Pointer to the custom_info_t struct containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_myalias(custom_info_t *info)
{
	int arg_index = 0;
	char *equal_sign_pos = NULL;
	list_t *alias_node = NULL;

	if (info->argc == 1)
	{
		alias_node = info->alias;
		while (alias_node)
		{
			custom_print_alias(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}

	arg_index = 1;
	do

	{
		equal_sign_pos = custom_strchr(info->argv[arg_index], '=');
		equal_sign_pos ? custom_set_alias(info, info->argv[arg_index]) :
custom_print_alias(node_starts_with(info->alias, info->argv[arg_index], '='));
	} while (info->argv[arg_index++]);

	return (0);
}
