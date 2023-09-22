#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
/*Function declarations*/
int string_length(char *s);
char *string_copy(char *destination, char *source);
char *string_concatenate(char *destination, char *source);
void print_string(char *str);
int compare_strings(char *str1, char *str2);
int _putchar(char c);
void _puts(char *str);
int print_character(char c);
char *string_duplicate(char *str);
char *read_input(void);
char **parse_input(char *input);
void display_prompt(void);
char **parse_path(char **input);
char **find_executable(char *input);
char *search_file(char *filename, char **path_list);
int execute_command(char **arguments, char *path, char **environment);
void print_environment(char **envp);
int is_valid_path(char *input);
int is_empty_input(char *input);
char *get_path_from_environment(char **env);
void remove_newline_character(char *str);
char *get_input_line(void);
#endif
