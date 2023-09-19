#include "main.h"

/**
 * custom_add_node - Adds a node to the start of the list.
 * @head: Address of pointer to head node.
 * @str: str field of node.
 * @num: Node index used by history.
 *
 * Return: Address of the new head node.
 */
custom_list_t *custom_add_node(custom_list_t **head, const char *str, int num)
{
	custom_list_t *new_head;

	if (!head)
		return (NULL);

	new_head = custom_malloc(sizeof(custom_list_t));
	if (!new_head)
		return (NULL);

	custom_memset((void *)new_head, 0, sizeof(custom_list_t));
	new_head->num = num;

	switch (str != NULL)

	{
		case 1:
			new_head->str = custom_strdup(str);
			if (!new_head->str)
			{
				custom_free(new_head);
				return (NULL);
			}
			break;
		default:
			break;
	}

	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * custom_add_node_end - Adds a node to the end of the list.
 * @head: Address of pointer to head node.
 * @str: str field of node.
 * @num: Node index used by history.
 *
 * Return: Address of the new node.
 */
custom_list_t *custom_add_node_end(custom_list_t **head,
		const char *str, int num)
{
	custom_list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = custom_malloc(sizeof(custom_list_t));
	if (!new_node)
		return (NULL);

	custom_memset((void *)new_node, 0, sizeof(custom_list_t));
	new_node->num = num;

	switch (str != NULL)

	{
		case 1:
			new_node->str = custom_strdup(str);
			if (!new_node->str)
			{
				custom_free(new_node);
				return (NULL);
			}
			break;
		default:
			break;
	}

	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * custom_print_list_str - Prints only the str
 * element of a custom_list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t custom_print_list_str(const custom_list_t *h)
{
	size_t i = 0;

	if (!h)
		return (0);

	do

	{
		custom_puts(h->str ? h->str : "(nil)");
		custom_puts("\n");
		h = h->next;
		i++;
	} while (h);

	return (i);
}

/**
 * custom_delete_node_at_index - Deletes a node at the given index.
 * @head: Address of pointer to the first node.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, 0 on failure.
 */
int custom_delete_node_at_index(custom_list_t **head, unsigned int index)
{
	custom_list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	switch (index)

	{
		case 0:
			node = *head;
			*head = (*head)->next;
			custom_free(node->str);
			custom_free(node);
			return (1);
		default:
			node = *head;
			for (i = 0; node && i < index; i++)
			{
				prev_node = node;
				node = node->next;
			}
			if (!node)
				return (0);
			prev_node->next = node->next;
			custom_free(node->str);
			custom_free(node);
			return (1);
	}
}

/**
 * custom_free_list - Frees all nodes of a custom_list_t list.
 * @head_ptr: Address of pointer to head node.
 *
 * Return: Void.
 */
void custom_free_list(custom_list_t **head_ptr)
{
	custom_list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;

	head = *head_ptr;
	node = head;
	do {
		next_node = node->next;
		custom_free(node->str);
		custom_free(node);
		node = next_node;
	} while (node);

	*head_ptr = NULL;
}
