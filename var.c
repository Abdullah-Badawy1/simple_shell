#include "main.h"

/**
 * custom_is_chain - Tests if the current
 * character in the buffer is a chain delimiter.
 * @info: The parameter struct.
 * @buf: The character buffer.
 * @p: Address of the current position in buf.
 *
 * Return: 1 if a chain delimiter is found, 0 otherwise.
 */
int custom_is_chain(custom_info_t *info, char *buf, size_t *p)
{
	size_t j = *p;
	char current_char = buf[j];
	char next_char = buf[j + 1];

	switch (current_char)
	{
	case '|':
		if (next_char == '|')
		{
			buf[j] = 0;
			j++;
			info->cmd_buf_type = CMD_OR;
			*p = j;
			return (1);
		}
		break;

	case '&':
		if (next_char == '&')
		{
			buf[j] = 0;
			j++;
			info->cmd_buf_type = CMD_AND;
			*p = j;
			return (1);
		}
		break;
	case ';':
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
		*p = j;
		return (1);
	default:
		break;
	}
	return (0);
}

/**
 * custom_check_chain - Checks if we should
 * continue chaining based on the last status.
 * @info: The parameter struct.
 * @buf: The character buffer.
 * @p: Address of the current position in buf.
 * @i: Starting position in buf.
 * @len: Length of buf.
 *
 * Return: Void.
 */
void custom_check_chain(custom_info_t *info,
		char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	switch (info->cmd_buf_type)
	{
	case CMD_AND:
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
		break;
	case CMD_OR:
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
		break;
	case CMD_CHAIN:
		buf[i] = 0;
		j = len;
		break;

	default:
		break;
	}
	*p = j;
}

/**
 * custom_replace_alias - Replaces an alias in the tokenized string.
 * @info: The parameter struct.
 *
 * Return: 1 if an alias was replaced, 0 otherwise.
 */
int custom_replace_alias(custom_info_t *info)
{
	int i;
	custom_list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
	node = custom_node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = custom_strchr(node->str, '=');
		if (!p)
			return (0);
		p = custom_strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * custom_replace_vars - Replaces
 * variables in the tokenized string.
 * @info: The parameter struct.
 *
 * Return: 1 if variables were replaced, 0 otherwise.
 */
int custom_replace_vars(custom_info_t *info)
{
	int i = 0;
	custom_list_t *node;

	while (info->argv[i])
	{
		char *current_arg = info->argv[i];

		if (current_arg[0] != '$' || !current_arg[1])
		{
			i++;
			continue;
		}
		switch (current_arg[1])
		{
		case '?':
			custom_replace_string(&(info->argv[i]),
			custom_strdup(custom_convert_number(info->status, 10, 0)));
			break;
		case '$':
			custom_replace_string(&(info->argv[i]),
				custom_strdup(custom_convert_number(getpid(), 10, 0)));
			break;
		default:
			node = custom_node_starts_with(info->env, &current_arg[1], '=');
			if (node)
			{
			custom_replace_string(&(info->argv[i]),
				custom_strdup(custom_strchr(node->str, '=') + 1));
			}
			else
			{
			custom_replace_string(&info->argv[i], custom_strdup(""));
			}
			break;
		}
		i++;
	}
	return (0);
}

/**
 * custom_replace_string - Replaces a string.
 * @old: Address of the old string.
 * @new: New string.
 *
 * Return: 1 if the string was replaced, 0 otherwise.
 */
int custom_replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
