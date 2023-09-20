#include "main.h"

/**
 * custom_strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: Integer length of the string.
 */
int custom_strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	do

	{
		i++;
	} while (*s++);

	return (i);
}

/**
 * custom_strcmp - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int custom_strcmp(char *s1, char *s2)
{
	do

	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	} while (*s1 && *s2);

	return (*s1 - *s2);
}

/**
 * custom_starts_with - Checks if the needle starts with the haystack.
 * @haystack: The string to search.
 * @needle: The substring to find.
 *
 * Return: Address of the next character of haystack or NULL.
 */
char *custom_starts_with(const char *haystack, const char *needle)
{
	do

	{
		if (*needle++ != *haystack++)
			return (NULL);
	} while (*needle);

	return ((char *)haystack);
}

/**
 * custom_strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 */
char *custom_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	do

	{
		*dest++ = *src++;
	} while (*src);

	*dest = *src;

	return (ret);
}
