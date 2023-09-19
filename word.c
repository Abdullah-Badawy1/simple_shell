#include "main.h"

/**
 * custom_strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *custom_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);

	do {
		dest[i] = src[i];
		i++;
	} while (src[i]);

	dest[i] = 0;
	return (dest);
}

/**
 * custom_strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *custom_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	str--;

	do {
		ret[length] = *str--;
		length--;
	} while (length >= 0);

	return (ret);
}

/**
 * custom_puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void custom_puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	do {
		custom_putchar(str[i]);
		i++;
	} while (str[i] != '\0');
}

/**
 * custom_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}
