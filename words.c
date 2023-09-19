#include "main.h"

/**
 * custom_strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int custom_strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * custom_strcmp - performs lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int custom_strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2 && (*s1 == *s2); s1++, s2++)
		;

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * custom_starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of the next character of haystack or NULL
 */
char *custom_starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);

	return ((char *)haystack);
}

/**
 * custom_strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to the destination buffer
 */
char *custom_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	for (; *src; src++, dest++)
		*dest = *src;

	*dest = *src;

	return (ret);
}
