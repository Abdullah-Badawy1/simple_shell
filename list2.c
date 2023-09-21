#include "main.h"

/**
 * custom_list_len - determines the length of a linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t custom_list_len(const custom_list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * custom_list_to_strings - returns an array of strings from custom_list_t->str
 * @head: pointer to the first node
 *
 * Return: array of strings
 */
char **custom_list_to_strings(custom_list_t *head)
{
	custom_list_t *node = head;
	size_t i = custom_list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = custom_malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = custom_malloc(custom_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				custom_free(strs[j]);
			custom_free(strs);
			return (NULL);
		}

		str = custom_strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * custom_print_list - prints all elements of a custom_list_t linked list
 * @h: pointer to the first node
 *
 * Return: size of list
 */
size_t custom_print_list(const custom_list_t *h)
{
	size_t i = 0;

	while (h)
	{
		custom_puts(custom_convert_number(h->num, 10, 0));
		custom_putchar(':');
		custom_putchar(' ');
		custom_puts(h->str ? h->str : "(nil)");
		custom_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * custom_node_starts_with - returns a node whose string starts with a prefix
 * @node: pointer to the list head
 * @prefix: string to match
 * @c: the next character after the prefix to match
 *
 * Return: matching node or null
 */
custom_list_t *custom_node_starts_with(custom_list_t *node,
		char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = custom_starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * custom_get_node_index - gets the index of a node
 * @head: pointer to the list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t custom_get_node_index(custom_list_t *head, custom_list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
