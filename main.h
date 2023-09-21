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
extern char **environ;
#define WRITE_BUF_SIZE 1024
#define CONVERT_UNSIGNED 0x01
#define CONVERT_LOWERCASE 0x02
#define BUF_FLUSH '\0'
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
#define USE_GETLINE 0
#define USE_STRTOK 0
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
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
 * struct custom_info_s - A structure to hold custom shell information.
 * @argc: The number of command-line arguments.
 * @fname: The name of the current input file (if any).
 * @line: The current input line.
 * @line_count: The count of lines read from input.
 * @status: The exit status of the most recent command.
 * @readfd: The file descriptor for reading input.
 * @prompt: The shell prompt to display.
 * @argv: An array of command-line arguments.
 * @env: A linked list of environment variables.
 * @alias: A linked list of alias definitions.
 * @cmd_buf_type: The type of command buffer (e.g., interactive or script).
 * @pipe: An array to hold pipe file descriptors.
 * @piped: A flag indicating if a command is piped.
 * @redir_type: The type of input/output redirection (if any).
 * @redir_fd: The file descriptor for redirection.
 * @redir_filename: The filename for redirection (if any).
 * @env_changed: A flag indicating if the environment has changed.
 * @environ: An array of environment variable strings.
 * @histcount: The count of command history entries.
 *
 * Description: This structure is used to store various attributes and
 * state information for a custom shell program. It keeps track of
 * command-line arguments, input/output, environment variables, and
 * other important shell-related data.
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
	int histcount;
} custom_info_t;

/* Function prototypes */
char *custom_convert_number(long int, int, int);
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
int custom_build_history_list(custom_info_t *info, char *buf, int linecount);
int custom_renumber_history(custom_info_t *info);
void custom_free(void *ptr);
char *custom_get_environment(custom_info_t *, const char *);
char *custom_get_environment(custom_info_t *info, const char *key);
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
size_t custom_print_list_str(const custom_list_t *);
int custom_set_custom_environment(custom_info_t *, char *, char *);
int custom_unset_custom_environment(custom_info_t *, char *);

#endif /* MAIN_H */
