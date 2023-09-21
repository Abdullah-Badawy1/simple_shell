#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - Entry point of the program.
 *
 * This program retrieves and prints the Parent Proces of the current process.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(void)
{
	pid_t my_ppid; /* Declare a variable to store the Parent (PPID) */

	my_ppid = getppid(); /* Get the PPID of the current process */
	printf("Parent Process ID (PPID): %u\n", my_ppid); /* Print the PPID */
	return (0); /* Return 0 to indicate successful execution */
}
