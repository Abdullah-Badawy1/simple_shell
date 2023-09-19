#include "main.h"

/**
 * custom_main - Entry point of the custom shell.
 * @info: Pointer to the custom_info_t struct.
 * @av: Argument vector.
 *
 * Return: 0 on success, 1 on error.
 */
int custom_main(custom_info_t *info, char **av)
{
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = custom_open(av[1], O_RDONLY);
		if (fd == -1)
		{
			switch (errno)
			{
				case EACCES:
					return (126);

				case ENOENT:
					custom_eputs(av[0]);
					custom_eputs(": 0: Can't open ");
					custom_eputs(av[1]);
					custom_eputchar('\n');
					custom_eputchar(BUF_FLUSH);
					return (127);

				default:
					return (EXIT_FAILURE);
			}
		}
		info->readfd = fd;
	}
	custom_populate_env_list(info);
	custom_read_history(info);
	custom_hsh(info, av);
	return (EXIT_SUCCESS);
}
