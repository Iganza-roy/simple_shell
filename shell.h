#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 64

void _promptme();
void read_cmd(char *cmd, size_t size);
void execute_cmd(const char *cmd);
void _printme(const char *text);

/* String Handlers */
size_t _strlen(const char *s);
size_t _strcspn(const char *s1, const char *s2);

#endif
