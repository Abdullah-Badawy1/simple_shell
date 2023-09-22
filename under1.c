#include "main.h"

/**
 * parse_input - split input line into arguments
 *
 * @input: input line from the user
 *
 * Return: array of strings
 */
char **parse_input(char *input)
{
	/* Declare variables */
	char **arguments = NULL;
	char *argument = NULL;
	size_t i = 0, j = 0;
	int count = 0;

	do

	{
		switch (input[i])
		{
			case ' ':
				count++;
				break;
		}
		i++;
	} while (input[i] != '\0');

	/* Check if the input consists of only spaces */
	if ((count + 1) == string_length(input))
		return (NULL);

	/* Allocate memory for the argument array */
	arguments = (char **)malloc(sizeof(char *) * (count + 2));
	if (arguments == NULL)
		return (NULL);
	argument = strtok(input, " \t\r");
	j = 0;
	do

	{
		arguments[j++] = argument;
	} while ((argument = strtok(NULL, " \t\r")) != NULL);

	/* Set the last element of the array to NULL for exec functions */
	arguments[j] = NULL;
	return (arguments);
}
