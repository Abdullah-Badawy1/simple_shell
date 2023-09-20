#include "main.h"

/**
 * custom_interactive - Returns true if the shell is in interactive mode.
 * @info: Struct address.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int custom_interactive(custom_info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * custom_is_delimiter - Checks if a character is a delimiter.
 * @c: The char to check.
 * @delimiter: The delimiter string.
 *
 * Return: 1 if true, 0 if false.
 */
int custom_is_delimiter(char c, char *delimiter)
{
	do

	{
		if (*delimiter++ == c)
			return (1);
	} while (*delimiter);

	return (0);
}

/**
 * custom_is_alpha - Checks for an alphabetic character.
 * @c: The character to check.
 *
 * Return: 1 if c is alphabetic, 0 otherwise.
 */
int custom_is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * custom_atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: 0 if no numbers in the string, converted number otherwise.
 */
int custom_atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
