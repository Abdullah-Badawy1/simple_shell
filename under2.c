#include "main.h"

/**
 * parse_path - split PATH environment variable into directories
 *
 * @env: environment variable array
 *
 * Return: array of directory paths
 */
char **parse_path(char **env)
{
	/* Declare variables */
	char *path_variable = get_path_from_environment(env);
	char **directories = NULL;
	char *directory = NULL;
	size_t i = 0, j = 0;
	int count = 0;

	do

	{
		if (path_variable[i] == ':')
			count++;
		i++;
	} while (path_variable[i] != '\0');
	/* Check if the PATH variable consists of only colons */
	if ((count + 1) == string_length(path_variable))
		return (NULL);
	directories = (char **)malloc(sizeof(char *) * (count + 2));
	if (directories == NULL)
		return (NULL);
	directory = strtok(path_variable, ":");
	j = 0;
	do

	{
		directories[j++] = directory;
	} while ((directory = strtok(NULL, ":")) != NULL);

	/* Set the last element of the array to NULL */
	directories[j] = NULL;
	return (directories);
}
