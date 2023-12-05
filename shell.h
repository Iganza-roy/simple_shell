#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKEN_SIZE 1024




void _print(const char *text);
void user_prompt(void);
void read_cmd(char *cmd, size_t size);
size_t _strcspn(const char *cmd, const char *reject);
pid_t execute_cmd(char *cmd);
int main(void);
void tokenize_cmd(char *cmd_line);

#endif

