#include "main.h"
#include <unistd.h> /* Include the necessary header for the 'write' function*/

/**
* _putchar - writes a character to standard output.
*
* This function writes the character 'c' to the standard output (usually the
* terminal). It uses the 'write' system call to perform this operation.
*
* @c: The character to print.
*
* Return: On success, it returns 1. On error, -1 is returned, and 'errno' is
* set appropriately to indicate the error.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _puts - prints a string to standard output.
*
* This function prints the string 'str' to the standard output (usually the
* terminal). It iterates through the characters in the string using a 'while'
* loop and calls '_putchar' to print each character. The loop continues until
* the null terminator ('\0') is encountered, marking the end of the string.
*
* @str: The input string to be printed.
*/
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++; /* Increment the index to move to the next character. */
	}
}
