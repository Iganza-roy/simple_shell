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
<<<<<<< HEAD
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
=======
typedef struct
{
        int is_itrv;
}in;
void _printme(const char *output, ...);
void user_prompt(in *inf);
void read_cmd(char *cmd, size_t size);
size_t _strcspn(const char *cmd, const char *reject);
pid_t execute_cmd(char *cmd);
int main(void);
void tokenize_cmd(char *cmd_line);
void exit_me(int status);
void print_env(void);
char *get_line(void);

void exit_status(char *cmd);
void exit_zero(char *cmd);
struct node {
        char *dir;
        struct node *next;
};
struct node *mk_path(char *pth, char del);

int path(void);
int set_env(const char *var, const char *val, int owr);
int unset_env(const char *var);
void _cd(const char *dir);

/*Handle strings*/

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void _strncpy(char *dest, char *src, size_t n);
char *_strdup(const char *s1);

>>>>>>> 7e25e2440cf36957b79543d742ce79dfb9c8e29a

#endif

