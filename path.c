#include "main.h"

/**
 * search_file - Search for a file in directories listed in PATH.
 *
 * @filename: Name of the file to search for.
 * @path_list: List of directory paths.
 *
 * Return: Path to the file if found, "0" if not found, or NULL on error.
 */
char *search_file(char *filename, char **path_list)
{
	int i = 0;
	char *file_path = NULL;
	struct dirent *entry = NULL;
	DIR *dir = NULL;

	do

	{
		dir = opendir(path_list[i]);
		if (dir == NULL)
			return (NULL);

		while ((entry = readdir(dir)) != NULL)
		{
			switch (entry->d_type)
			{
				case DT_REG:
					if (compare_strings(entry->d_name, filename, string_length(filename)) == 0)
					{
					file_path = (char *)malloc(string_length(path_list[i]) + string_length(filename) + 2);
						if (file_path == NULL)
						{
							closedir(dir);
							return (NULL);
						}
						string_copy(file_path, path_list[i]);
						string_concatenate(file_path, "/");
						string_concatenate(file_path, filename);
						closedir(dir);
						return (file_path);
					}
					break;
			}
		}
		closedir(dir);
		i++;
	} while (path_list[i] != NULL);

	return (string_duplicate("0"));
}
