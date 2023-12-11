#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKEN_SIZE 1024
#define MAX_PATH_LEN 1024
#define BUFF_SIZE 1024
#define MAX_OUTPUT_SIZE 512

void _printme(const char *output, ...);
void user_prompt(void);
void read_cmd(char *cmd, size_t size);
size_t _strcspn(const char *cmd, const char *reject);
pid_t execute_cmd(char *cmd);
int main(void);
void tokenize_cmd(char *cmd_line);
void exit_me(int status);
void print_env(void);
//void get_path(char *cmd);
char *get_line(void);

void exit_status(char *cmd);
void exit_zero(char *cmd);


#endif

