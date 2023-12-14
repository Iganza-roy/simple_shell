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
#define MAX_ALIASES 32

extern char **environ;
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


#endif

