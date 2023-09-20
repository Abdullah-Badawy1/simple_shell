#include "main.h"

/**
 * main - Entry point of the program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	custom_info_t info[] = { CUSTOM_INFO_INIT };
	int fd = 2;

	/* Using inline assembly to demonstrate a point */
	asm (
		"mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd)
	);

	/* Ternary operator used to set 'fd' based on 'ac' value */
	fd = (ac == 2) ? open(av[1], O_RDONLY) : fd;

	if (fd == -1)
	{
		/* Ternary operator used to handle different 'errno' values */
		(errno == EACCES) ?
			exit(126) :
			(errno == ENOENT) ?
				(void)(
					custom_eputs(av[0]),
					custom_eputs(": 0: Can't open "),
					custom_eputs(av[1]),
					custom_eputchar('\n'),
					custom_eputchar(BUF_FLUSH),
					exit(127)
				) :
				(void)0; /* Default case */
		return (EXIT_FAILURE);
	}

	info->readfd = fd;

	custom_populate_environment_list(info);
	custom_read_history(info);
	custom_main(info, av);
	return (EXIT_SUCCESS);
}
