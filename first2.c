#include "main.h"

/**
 * _strncmp - compare two strings up to a specified length
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 *
 * Return: size_t
 */
size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];
		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}
/**
 * get_path_from_environment - get the PATH environment variable
 *
 * @env: environment variable array
 *
 * Return: string containing the PATH or NULL if not found
 */
char *get_path_from_environment(char **env)
{
	size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	do

	{
		if (compare_strings(env[index], "PATH=") == 0)
			break;
		index++;
	} while (env[index] != NULL);
	if (env[index] == NULL)
		return (NULL);

	do

	{
		var++;
		count++;
	} while (env[index][var] != '\0');
	path = (char *)malloc(sizeof(char) * (count + 1));
	if (path == NULL)
		return (NULL);

	var = 5;
	count = 0;
	do

	{
		path[count] = env[index][var];
		var++;
		count++;
	} while (env[index][var] != '\0');

	path[count] = '\0';
	return (path);
}
