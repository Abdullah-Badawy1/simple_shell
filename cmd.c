#include "main.h"

/**
 * custom_is_cmd - Determines if a file is an executable command.
 * @info: The info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */
int custom_is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	return ((path && !stat(path, &st) && (st.st_mode & S_IFREG)) ? 1 : 0);
}

/**
 * custom_dup_chars - Duplicates characters.
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to a new buffer.
 */
char *custom_dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		buf[k++] = (pathstr[i] != ':') ? pathstr[i] : '\0';

	buf[k] = '\0';
	return (buf);
}

/**
 * custom_find_path - Finds this cmd in the PATH string.
 * @info: The info struct.
 * @pathstr: The PATH string.
 * @cmd: The cmd to find.
 *
 * Return: Full path of cmd if found or NULL.
 */
char *custom_find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path = NULL;

	if (!pathstr)
		return (NULL);

	if ((_strlen(cmd) > 2) && custom_starts_with(cmd, "./"))
		return (custom_is_cmd(info, cmd) ? cmd : NULL);

	while (1)
	{
		if (!pathstr[i] || (pathstr[i] == ':'))
		{
			path = custom_dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
				_strcat(path, "/");
			_strcat(path, cmd);

			if (custom_is_cmd(info, path))
				return (path);

			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}

	return (NULL);
}
