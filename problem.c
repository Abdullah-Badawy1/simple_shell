#include "main.h"

/**
 * custom_eputs - Prints an input string to stderr.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void custom_eputs(char *str)
{
	int index = 0;

	/* Check if the input string is not NULL */
	if (!str)
		return;

	do

	{
		/* Print each character to stderr */
		custom_eputchar(str[index]);
		index++;
	} while (str[index] != '\0');
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
	static int buffer_index;
	static char write_buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
		write(2, write_buffer, buffer_index);
		buffer_index = 0;
	}

	if (c != BUF_FLUSH)
		write_buffer[buffer_index++] = c;

	return (1);
}

/**
 * custom_putfd - Writes the character c to the given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_putfd(char c, int fd)
{
	static int buffer_index;
	static char write_buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
		write(fd, write_buffer, buffer_index);
		buffer_index = 0;
	}

	/* If the character is not a flush command, store it in the buffer */
	if (c != BUF_FLUSH)
		write_buffer[buffer_index++] = c;

	return (1);
}

/**
 * custom_putsfd - Prints an input string to the given file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int custom_putsfd(char *str, int fd)
{
	int char_count = 0;

	/* If the input string is NULL, return 0 */
	if (!str)
		return (0);

	do

	{
		char_count += custom_putfd(*str++, fd);
	} while (*str);

	return (char_count);
}
