#include "main.h"

/**
 * custom_erratoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted number if successful, -1 on error.
 */
int custom_erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* Skip the plus sign if present */

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			result = (result > INT_MAX) ? -1 : result;
		}
		else
			return (-1); /* Error: Invalid character */
	}

	return (result);
}

/**
 * custom_print_error - Prints an error message.
 * @info: The parameter & return info struct.
 * @error_type: String containing the specified error type.
 */
void custom_print_error(info_t *info, char *error_type)
{
	custom_eputs(info->fname);
	custom_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	custom_eputs(": ");
	custom_eputs(info->argv[0]);
	custom_eputs(": ");
	custom_eputs(error_type);
}

/**
 * custom_print_d - Prints a decimal (integer) number (base 10).
 * @input: The input number.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters printed.
 */
int custom_print_d(int input, int fd)
{
	int (*custom_putchar)(char) = custom_putfd;
	int count = 0;
	unsigned int abs_value = (input < 0) ? -input : input;
	unsigned int current = abs_value;

	if (fd == STDERR_FILENO)
		custom_putchar = custom_eputchar;

	do

	{
		custom_putchar('0' + current / 10);
		count++;
		current %= 10;
	} while (current != 0);

	return (count);
}

/**
 * custom_convert_number - Converter function for integers to strings.
 * @num: The number to convert.
 * @base: The base for conversion.
 * @flags: Argument flags.
 *
 * Return: A string representation of the number.
 */
char *custom_convert_number(long int num, int base, int flags)
{
	static char *digit_array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? -num : num;

digit_array = (flags & CONVERT_LOWERCASE) ?
"0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do

	{
		*--ptr = digit_array[n % base];
		n /= base;
	} while (n != 0);

	if (num < 0 && !(flags & CONVERT_UNSIGNED))
		*--ptr = '-';

	return (ptr);
}

/**
 * custom_remove_comments - Replaces the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 */
void custom_remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
