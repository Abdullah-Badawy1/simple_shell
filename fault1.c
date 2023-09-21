#include "main.h"

/**
 * custom_eputs - Prints an input string.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void custom_eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		custom_eputchar(str[i]);
		i++;
	}
}

/**
 * custom_eputchar - Writes the character c to stderr.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
	case BUF_FLUSH:
		if (i >= WRITE_BUF_SIZE)
		{
			write(2, buf, i);
			i = 0;
		}
		break;
	default:
		buf[i++] = c;
		break;
	}

	return (1);
}

/**
 * custom_putfd - Writes the character c to the given fd.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
	case BUF_FLUSH:
		if (i >= WRITE_BUF_SIZE)
		{
			write(fd, buf, i);
			i = 0;
		}
		break;
	default:
		buf[i++] = c;
		break;
	}

	return (1);
}

/**
 * custom_putsfd - Prints an input string.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int custom_putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	do

	{
		i += custom_putfd(*str++, fd);
	} while (*str);

	return (i);
}
