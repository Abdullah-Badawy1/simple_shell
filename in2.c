#include "main.h"

/**
 * custom_history - Displays the history list,
 * one command per line, preceded
 *                 with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_history(custom_info_t *info)
{
	custom_print_list(info->history);
	return (0);
}

/**
 * custom_unset_alias - Unsets an alias.
 * @info: Parameter struct.
 * @str: The alias string.
 *
 * Return: 0 on success, 1 on error.
 */
int custom_unset_alias(custom_info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = custom_strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = custom_delete_node_at_index(&(info->alias),
		custom_get_node_index
		(info->alias, custom_node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * custom_set_alias - Sets an alias.
 * @info: Parameter struct.
 * @str: The alias string.
 *
 * Return: 0 on success, 1 on error.
 */
int custom_set_alias(custom_info_t *info, char *str)
{
	char *p;

	p = custom_strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (custom_unset_alias(info, str));

	custom_unset_alias(info, str);
	return (custom_add_node_end(&(info->alias), str, 0) == NULL ? 1 : 0);
}

/**
 * custom_print_alias - Prints an alias string.
 * @node: The alias node.
 *
 * Return: 0 on success, 1 on error.
 */
int custom_print_alias(custom_list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = custom_strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			custom_putchar(*a);
		custom_putchar('\'');
		custom_puts(p + 1);
		custom_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * custom_alias - Mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int custom_alias(custom_info_t *info)
{
	int i = 0;
	char *p = NULL;
	custom_list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		do

		{
			custom_print_alias(node);
			node = node->next;
		} while (node);
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = custom_strchr(info->argv[i], '=');
		if (p)
			custom_set_alias(info, info->argv[i]);
		else
	custom_print_alias(custom_node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
