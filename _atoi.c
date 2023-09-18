#include "main.h"

/**
 * custom_interactive - Check if the shell is in interactive mode.
 * @info: Pointer to the custom_info_t struct.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int custom_interactive(custom_info_t *info)
{
	int itermode = isatty(STDIN_FILENO);
	int readfd = info->readfd;

	return (itermode && readfd <= 2);
}

/**
 * custom_is_delim - Check if a character is a delimiter.
 * @c: The character to check.
 * @delim: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int custom_is_delim(char c, char *delim)
{
	int is_delimiter = 0;

	for (int i = 0; delim[i]; i++)
	{
		if (delim[i] == c)
		{
			is_delimiter = 1;
			break;
		}
	}
	return (is_delimiter);
}

/**
 * custom_is_alpha - Check if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int custom_is_alpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}

/**
 * custom_atoi - Convert a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer if successful, 0 if no numbers in the string.
 */
int custom_atoi(char *s)
{
	int index = 0;
	int sign = 1;
	int flag = 0;
	unsigned int result = 0;

	while (s[index] != '\0' && flag != 2)
	{
		sign = (s[index] == '-') ? -sign : sign;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			result = (result * 10) + (s[index] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}

		index++;
	}

	return ((sign == -1) ? -result : result);
}
