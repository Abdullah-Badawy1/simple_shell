#ifndef _MAIN_H_
#define _MAIN_H_

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

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".custom_shell_history"
#define HIST_MAX 4096

extern char **environ;
/**
 * struct custom_liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct custom_liststr
{
	int num;
	char *str;
	struct custom_liststr *next;
} custom_list_t;
/**
 *struct custom_info - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct custom_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	custom_list_t *env;
	custom_list_t *history;
	custom_list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} custom_info_t;

#define CUSTOM_INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 *struct custom_builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct custom_builtin
{
	char *type;
	int (*func)(custom_info_t *);
} custom_builtin_table;


int custom_main(custom_info_t *, char **);
int custom_find_builtin(custom_info_t *);
void custom_find_command(custom_info_t *);
void custom_fork_command(custom_info_t *);

int custom_is_command(custom_info_t *, char *);
char *custom_duplicate_characters(char *, int, int);
char *custom_find_path(custom_info_t *, char *, char *);

int custom_loop_main(char **);

void custom_eputs(char *);
int custom_eputchar(char);
int custom_putfd(char c, int fd);
int custom_putsfd(char *str, int fd);

int custom_strlen(char *);
int custom_strcmp(char *, char *);
char *custom_starts_with(const char *, const char *);
char *custom_strcat(char *, char *);

char *custom_strcpy(char *, char *);
char *custom_strdup(const char *);
void custom_puts(char *);
int custom_putchar(char);


char **custom_str_to_words(char *, char *);
char **custom_str_to_words_v2(char *, char);

char *custom_memset(char *, char, unsigned int);
void custom_free(char **);
void *custom_realloc(void *, unsigned int, unsigned int);

int custom_free_memory(void **);

int custom_interactive(custom_info_t *);
int custom_is_delimiter(char, char *);
int custom_is_alpha(int);
int custom_atoi(char *);

int custom_error_atoi(char *);
void custom_print_error(custom_info_t *, char *);
int custom_print_d(int, int);
char *custom_convert_number(long int, int, int);
void custom_remove_comments(char *);

int custom_exit_main(custom_info_t *);
int custom_change_directory(custom_info_t *);
int custom_help(custom_info_t *);

int custom_history(custom_info_t *);
int custom_alias(custom_info_t *);

ssize_t custom_get_input(custom_info_t *);
int custom_get_line(custom_info_t *, char **, size_t *);
void custom_sigint_handler(int);

void custom_clear_info(custom_info_t *);
void custom_set_info(custom_info_t *, char **);
void custom_free_info(custom_info_t *, int);

char *custom_get_environment(custom_info_t *, const char *);
int custom_custom_environment(custom_info_t *);
int custom_set_environment(custom_info_t *);
int custom_unset_environment(custom_info_t *);
int custom_populate_environment_list(custom_info_t *);

char **custom_get_environ(custom_info_t *);
int custom_unset_custom_environment(custom_info_t *, char *);
int custom_set_custom_environment(custom_info_t *, char *, char *);

char *custom_get_history_file(custom_info_t *info);
int custom_write_history(custom_info_t *info);
int custom_read_history(custom_info_t *info);
int custom_build_history_list(custom_info_t *info, char *buf, int linecount);
int custom_renumber_history(custom_info_t *info);

custom_list_t *custom_add_node(custom_list_t **, const char *, int);
custom_list_t *custom_add_node_end(custom_list_t **, const char *, int);
size_t custom_print_list_str(const custom_list_t *);
int custom_delete_node_at_index(custom_list_t **, unsigned int);
void custom_free_list(custom_list_t **);

size_t custom_list_length(const custom_list_t *);
char **custom_list_to_strings(custom_list_t *);
size_t custom_print_list(const custom_list_t *);
custom_list_t *custom_node_starts_with(custom_list_t *, char *, char);
ssize_t custom_get_node_index(custom_list_t *, custom_list_t *);

int custom_is_chain(custom_info_t *, char *, size_t *);
void custom_check_chain(custom_info_t *, char *, size_t *, size_t, size_t);
int custom_replace_alias(custom_info_t *);
int custom_replace_variables(custom_info_t *);
int custom_replace_string(char **, char *);

char *custom_strncpy(char *dest, const char *src, size_t n);
char *custom_strncat(char *dest, const char *src, size_t n);
char *custom_strchr(const char *s, int c);
#endif
