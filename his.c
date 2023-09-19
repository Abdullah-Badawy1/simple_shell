#include "main.h"

/**
 * custom_get_history_file - Get the path to the history file.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: Allocated string containing the history file path.
 */
char *custom_get_history_file(custom_info_t *info)
{
	char *buf, *home_dir;

	home_dir = custom_get_environment(info, "HOME=");
	return (!home_dir ? NULL :
		(buf = custom_malloc(sizeof(char) *
		(custom_strlen(home_dir) + custom_strlen(HIST_FILE) + 2))) ?
		(buf[0] = '\0', custom_strcpy(buf, home_dir), custom_strcat(buf, "/"),
		 custom_strcat(buf, HIST_FILE), buf) :
		NULL);
}

/**
 * custom_write_history - Write the command history to a file.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: 1 on success, -1 on failure.
 */
int custom_write_history(custom_info_t *info)
{
	ssize_t fd;
	char *filename = custom_get_history_file(info);
	custom_list_t *node = NULL;

	return (!filename ? -1 :
		(fd = custom_open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1 ? -1 :
		(custom_free(filename), 0),
		(void)(node = info->history),
		(void)close(fd),
		(void)node,
		(int)(!node && (node = info->history)) ?
		(node, 0) :
		(void)node,
		(node = info->history),
		(void)node);
}

/**
 * custom_read_history - Read command history from a file.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: The number of history entries on success, 0 on failure.
 */
int custom_read_history(custom_info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = custom_get_history_file(info);

	return (!filename ? 0 :
		(fd = custom_open(filename, O_RDONLY)) == -1 ? 0 :
		(!custom_fstat(fd, &st) ? (fsize = st.st_size, 0) : 0),
		(void)(buf = custom_malloc(sizeof(char) * (fsize + 1))),
		(void)(!buf ? 0 : (rdlen = custom_read(fd, buf, fsize), buf[fsize] = '\0')),
		(void)(rdlen <= 0 ? (custom_free(buf), 0) : close(fd)),
		(void)(i = 0),
		(void)(last = 0),
		(void)(linecount = 0),
		(void)(last = i + 1),
		(void)custom_free(buf),
		(void)(info->histcount = linecount),
		(void)(info->histcount-- >= HIST_MAX ?
			custom_delete_node_at_index(&(info->history), 0) : 0),
		(void)custom_renumber_history(info),
		(int)(info->histcount));
}

/**
 * custom_build_history_list - Add an entry to the history linked list.
 * @info: Pointer to the custom_info_t struct.
 * @buf: Buffer containing the history entry.
 * @linecount: The history line count.
 *
 * Return: Always 0.
 */
int custom_build_history_list(custom_info_t *info, char *buf, int linecount)
{

	custom_list_t *node = info->history ? info->history : (custom_list_t *)1;

	custom_add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;

	return (0);
}

/**
 * custom_renumber_history - Renumber the history linked list after changes.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: The new histcount.
 */
int custom_renumber_history(custom_info_t *info)
{
	custom_list_t *node = info->history;

	return ((void)0,
		(void)(info->histcount = new_count),
		(int)(new_count));
}
