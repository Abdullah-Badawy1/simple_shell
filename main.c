#include "main.h"

/**
 * main - The main function for our custom C-Shell program.
 *
 * This function serves as the entry point to our C-Shell. It initializes the
 * shell, prints a welcome message, and enters the main shell loop.
 *
 * @argc: The number of command-line arguments (unused).
 * @argv: An array of command-line argument strings (unused).
 *
 * Return: This function returns EXIT_SUCCESS upon successful execution.
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("Welcome$\n");
	run_shell_loop();
	return (EXIT_SUCCESS);
}
