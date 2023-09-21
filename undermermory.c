#include "main.h"

/**
 * custom_is_cmd - Determines if a file is an executable command.
 * @info: The custom_info_t struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */
int custom_is_cmd(custom_info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
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
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}
/**
 * custom_find_path - Finds the cmd in the PATH string.
 * @info: The custom_info_t struct.
 * @pathstr: The PATH string.
 * @cmd: The cmd to find.
 *
 * Return: Full path of cmd if found or NULL.
 */
char *custom_find_path(custom_info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);

	if ((custom_strlen(cmd) > 2) && custom_starts_with(cmd, "./"))
	{
		if (custom_is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = custom_dup_chars(pathstr, curr_pos, i);

			if (!*path)
				custom_strcat(path, cmd);
			else
			{
				custom_strcat(path, "/");
				custom_strcat(path, cmd);
			}
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
