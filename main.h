#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define TOKEN_BUFFER_SIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"

int main(int argc, char **argv);
int change_directory(char **args);
int exit_shell(char **args);
int num_builtin_commands(void);
int launch_process(char **args);
char *read_input_line(void);
int execute_command(char **args);
void run_shell_loop(void);
char **split_input_line(char *line);
char *get_environment_variable(char *name);
char *find_executable(char *command, char *path);
int check_path_for_executable(char **argv);

#endif
