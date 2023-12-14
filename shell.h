#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* env vars */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

void _prompt(void);
int _putchar(char c);
int _printme(char *str);
void free_me(char **buffer);
void _exe(char *cmd, char **cmds);
void signal_me(int n);
char **tokenize_me(char *l);
char *path_test(char **p, char *cmd);
char *add_path(char *p, char *cmd);
char *path_finder(void);
void _env(void);
int b_helper(char **cmd, char *s);
int _builtin(char **cmd, char *l);
void exit_me(char **cmd, char *l);

/* String handlers */
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char s);
char *_strdup(char *str);
int _strlen(char *str);
int _strncmp(char *str1, char *str2, int n);

struct fg
{
	bool interact;
} fg;

struct x
{
	int f;
	int lc;
} x;

struct y
{
	char *exit;
	char *env;
} y;

#endif

