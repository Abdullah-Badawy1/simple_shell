#include "main.h"

/**
 * custom_clear_info - Initializes the info_t struct.
 * @info: Pointer to the info_t struct.
 */
void custom_clear_info(custom_info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * custom_set_info - Initializes the info_t struct.
 * @info: Pointer to the info_t struct.
 * @av: Argument vector.
 */
void custom_set_info(custom_info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	info->arg ? (info->argv = custom_str_to_words(info->arg, " \t")) : (
		info->argv = malloc(sizeof(char *) * 2),
		info->argv ? (
			info->argv[0] = custom_strdup(info->arg),
			info->argv[1] = NULL
		) : (void)0
	);
	for (i = 0; info->argv && info->argv[i]; i++)
		;
	info->argc = i;

	replace_alias(info);
	replace_vars(info);
}

/**
 * custom_free_info - Frees the fields of the info_t struct.
 * @info: Pointer to the info_t struct.
 * @free_all: True if freeing all fields.
 */
void custom_free_info(custom_info_t *info, int free_all)
{
	custom_free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (free_all)
	{
		!info->cmd_buf ? free(info->arg) : (void)0;
		info->env ? custom_free_list(&(info->env)) : (void)0;
		info->history ? custom_free_list(&(info->history)) : (void)0;
		info->alias ? custom_free_list(&(info->alias)) : (void)0;
		custom_free(info->environ);
		info->environ = NULL;
		info->cmd_buf ? custom_free_memory((void **)info->cmd_buf) : (void)0;
		info->readfd > 2 ? close(info->readfd) : (void)0;
		custom_putchar(BUF_FLUSH);
	}
}
