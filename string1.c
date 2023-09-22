#include "main.h"
#include <stddef.h>
/**
 * string_length - Calculate the length of a string.
 *
 * @s: Input string.
 *
 * Return: Length of the string.
 */
int string_length(char *s)
{
	int length = 0;

	do

	{
		length++;
	} while (s[length] != '\0');

	return (length);
}

/**
 * string_copy - Copy a string.
 *
 * @destination: Destination string.
 * @source: Source string.
 *
 * Return: Pointer to destination.
 */
char *string_copy(char *destination, char *source)
{
	int i = 0;

	do

	{
		destination[i] = source[i];
		i++;
	} while (source[i] != '\0');

	destination[i] = '\0';

	return (destination);
}

/**
 * string_concatenate - Concatenate two strings.
 *
 * @destination: Destination string.
 * @source: Source string.
 *
 * Return: Pointer to destination.
 */
char *string_concatenate(char *destination, char *source)
{
	int dest_len = string_length(destination);
	int i = 0;

	do

	{
		destination[dest_len + i] = source[i];
		i++;
	} while (source[i] != '\0');

	destination[dest_len + i] = '\0';

	return (destination);
}

/**
 * compare_strings - Compare two strings.
 *
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: 0 if strings are equal, otherwise the difference.
 */

int compare_strings(char *str1, char *str2)
{
	int i = 0;

	do

	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	} while (str1[i] != '\0' && str2[i] != '\0');

	return (0);
}
/**
 * string_duplicate - Duplicate a string.
 *
 * @str: Input string.
 *
 * Return: Pointer to the duplicated string.
 */
char *string_duplicate(char *str)
{
	char *duplicate;
	int length = string_length(str);
	int i = 0;

	duplicate = malloc(length + 1);

	if (duplicate == NULL)
		return (NULL);

	do

	{
		duplicate[i] = str[i];
		i++;
	} while (i <= length);

	return (duplicate);
}
