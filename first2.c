#include "main.h"

/**
 * compare_strings - compare two strings up to a specified length
 *
 * @str1: first string
 * @str2: second string
 * @n: number of characters to compare
 *
 * Return: (0) if strings are equal up to n characters,
 * otherwise the difference
 */
int compare_strings(char *str1, char *str2, size_t n)
{
	size_t i = 0;

	do

	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	} while (str1[i] != '\0' && str2[i] != '\0' && i < n);

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
		if (compare_strings(env[index], "PATH=", 5) == 0)
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
