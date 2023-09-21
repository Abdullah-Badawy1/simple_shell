#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

/* Structs */
/**
 * struct custom_list_s - A structure to represent a custom list node.
 * @num: An integer value.
 * @str: A string value.
 * @next: Pointer to the next node in the list.
 */
typedef struct custom_list_s
{
	int num;
	char *str;
	struct custom_list_s *next;
} custom_list_t;
/**
 * struct custom_info_s - A structure to hold custom information.
 * @fname: File name.
 * @line: A line of text.
 * @line_count: Line count.
 * @status: Status code.
 * @readfd: Read file descriptor.
 * @prompt: User prompt.
 * @argv: Command-line arguments.
 * @env: Environment variables.
 * @alias: Alias list.
 * @cmd_buf_type: Command buffer type.
 * @pipe: Pipe array.
 * @piped: Piped flag.
 * @redir_type: Redirection type.
 * @redir_fd: Redirection file descriptor.
 * @redir_filename: Redirection filename.
 */
typedef struct custom_info_s
{
	int argc;
	char *fname;
	char *line;
	int line_count;
	int status;
	int readfd;
	char *prompt;
	char **argv;
	custom_list_t *env;
	custom_list_t *alias;
	int cmd_buf_type;
	int pipe[2];
	int piped;
	int redir_type;
	int redir_fd;
	char *redir_filename;
	int env_changed;
	char **environ;
} custom_info_t;

/* Function prototypes */
char *custom_malloc(size_t size);
void custom_free(void *ptr);
void custom_add_node_end(custom_list_t **head, char *data, int alloc);
char **custom_list_to_strings(custom_list_t *list);
int custom_delete_node_at_index(custom_list_t **list, int index);
int custom_bfree(void **ptr);
void custom_eputs(char *str);
int custom_eputchar(char c);
int custom_putfd(char c, int fd);
int custom_putsfd(char *str, int fd);
int custom_erratoi(char *s);
void custom_print_error(custom_info_t *info, char *estr);
int custom_print_d(int input, int fd);
char *custom_convert_number(long int num, int base, int flags);
void custom_remove_comments(char *buf);
int custom_strlen(char *s);
int custom_strcmp(char *s1, char *s2);
char *custom_starts_with(const char *haystack, const char *needle);
char *custom_strcat(char *dest, char *src);
char *custom_strcpy(char *dest, char *src);
char *custom_strdup(const char *str);
void custom_puts(char *str);
int custom_putchar(char c);
char **custom_strtow(char *str, char *d);
char **custom_strtow2(char *str, char d);
int custom_is_cmd(custom_info_t *info, char *path);
char *custom_dup_chars(char *pathstr, int start, int stop);
char *custom_find_path(custom_info_t *info, char *pathstr, char *cmd);
int custom_is_chain(custom_info_t *info, char *buf, size_t *p);
void custom_check_chain(custom_info_t *info,
		char *buf, size_t *p, size_t i, size_t len);
int custom_replace_alias(custom_info_t *info);
int custom_replace_vars(custom_info_t *info);
int custom_replace_string(char **old, char *new);

#endif /* MAIN_H */
