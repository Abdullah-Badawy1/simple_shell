#include "main.h"

/**
 * custom_list_length - Determines the length of the linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t custom_list_length(const custom_list_t *h)
{
	size_t i = 0;

	do

	{
		h = h->next;
		i++;
	} while (h);

	return (i);
}

/**
 * custom_list_to_strings - Returns an array of strings from the list->str.
 * @head: Pointer to the first node.
 *
 * Return: Array of strings.
 */
char **custom_list_to_strings(custom_list_t *head)
{
	custom_list_t *node = head;
	size_t i = custom_list_length(head), j;
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
 * custom_print_list - Prints all elements of a custom_list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t custom_print_list(const custom_list_t *h)
{
	size_t i = 0;

	do

	{
		custom_puts(custom_convert_number(h->num, 10, 0));
		custom_putchar(':');
		custom_putchar(' ');
		custom_puts(h->str ? h->str : "(nil)");
		custom_puts("\n");
		h = h->next;
		i++;
	} while (h);

	return (i);
}

/**
 * custom_node_starts_with - Returns a node whose string starts with a prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match.
 * @c: The next character after prefix to match.
 *
 * Return: Matching node or NULL.
 */
custom_list_t *custom_node_starts_with(custom_list_t *node,
		char *prefix, char c)
{
	char *p = NULL;

	do

	{
		p = custom_starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	} while (node);

	return (NULL);
}

/**
 * custom_get_node_index - Gets the index of a node.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: Index of the node or -1.
 */
ssize_t custom_get_node_index(custom_list_t *head, custom_list_t *node)
{
	size_t i = 0;

	do

	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	} while (head);

	return (-1);
}
