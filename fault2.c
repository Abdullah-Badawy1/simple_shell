#include "main.h"
/**
 * custom_erratoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: 0 if no numbers in the string, the converted number otherwise,
 *         -1 on error.
 */
int custom_erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	while (s[i] != '\0')
	{
		switch (s[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				result *= 10;
				result += (s[i] - '0');
				if (result > INT_MAX)
					return (-1);
				break;
			default:
				return (-1);
		}
		i++;
	}
	return (result);
}

/**
 * custom_print_error - Prints an error message.
 * @info: The parameter & return info struct.
 * @estr: String containing the specified error type.
 *
 * Return: 0 if no numbers in the string, the converted number otherwise,
 *        -1 on error.
 */
void custom_print_error(custom_info_t *info, char *estr)
{
	custom_eputs(info->fname);
	custom_eputs(": ");
	custom_print_d(info->line_count, STDERR_FILENO);
	custom_eputs(": ");
	custom_eputs(info->argv[0]);
	custom_eputs(": ");
	custom_eputs(estr);
}

/**
 * custom_print_d - Function prints a decimal (integer) number (base 10).
 * @input: The input.
 * @fd: The file descriptor to write to.
 *
 * Return: Number of characters printed.
 */
int custom_print_d(int input, int fd)
{
	int (*__putchar)(char) = custom_putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = custom_eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	while (current > 0)
	{
		i = current % 10;
		__putchar('0' + i);
		count++;
		current /= 10;
	}
	__putchar('0' + current);
	count++;
	return (count);
}

/**
 * custom_convert_number - Converter function, a clone of itoa.
 * @num: Number.
 * @base: Base.
 * @flags: Argument flags.
 *
 * Return: String.
 */
char *custom_convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do

	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * custom_remove_comments - Function replaces
 * the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 *
 * Return: Always 0.
 */
void custom_remove_comments(char *buf)
{
	int i = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
		i++;
	}
}
