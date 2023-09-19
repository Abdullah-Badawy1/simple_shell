#include "main.h"

/**
 * custom_strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: A pointer to the destination string.
 */
char *custom_strncpy(char *dest, char *src, int n)
{
	char *result = dest;

	for (int i = 0, j = 0; i < n - 1 && src[i] != '\0'; i++, j++)
	{
		dest[i] = src[i];
	}

	for (int i = n - 1; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (result);
}

/**
 * custom_strncat - Concatenates two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 *
 * Return: A pointer to the concatenated string.
 */
char *custom_strncat(char *dest, char *src, int n)
{
	char *result = dest;

	for (int i = 0, j = 0; dest[i] != '\0'; i++, j++)
		;

	for (int i = 0, j = 0; src[j] != '\0' && j < n; i++, j++)
	{
		dest[i] = src[j];
	}

	dest[(n < j) ? n : j] = '\0';

	return (result);
}

/**
 * custom_strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the first occurrence
 * of the character in the string,
 *         or NULL if the character is not found.
 */
char *custom_strchr(char *s, char c)
{
	do

	{
		if (*s == c)
		{
			return (s);
		}
	} while (*s++ != '\0');

	return (NULL);
}
