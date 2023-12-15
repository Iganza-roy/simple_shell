#ifndef SHELL_H
#define SHELL_H


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
#include <stddef.h>
#include <signal.h>

#define useGetLine 0
#define cmdNormal 0
#define orChain 1
#define andChain 2
#define cmdChain 3
#define lowerCaseConverter 1
#define unsignedConverter 2
#define readBufferSize 1024
#define writeBufferSize 1024
#define bufferFlush -1


#define fileHistory ".simple_shell_history"
#define maxHistory 4096

extern char **environ;


/**
 * struct stringList - .....
 * @number: ....
 * @string: ....
 * @next_node: ....
 */
typedef struct stringList
{
	int number;
	char *string;
	struct stringList *next_node;
} stringlist_t;

/**
 * struct PassedInformation - ...
 * @argument: ...
 * @argument_v: ...
 * @str_path: ....
 * @argument_c: ...
 * @err_line_num: ....
 * @err_code: .....
 * @linenumflag: ....
 * @filename: ...
 * @envir: ....
 * @environ: ...
 * @my_history: ...
 * @my_alias: ....
 * @isenvchange: ....
 * @my_status: ....
 * @cmdBuffer: ....
 * @cmdBufferTybe: ...
 * @rfd: ...
 * @histnum: ....
 */
typedef struct PassedInformation
{
	char *argument;
	char **argument_v;
	char *str_path;
	int argument_c;
	unsigned int err_line_num;
	int err_code;
	int linenumflag;
	char *filename;
	stringlist_t *envir;
	stringlist_t *my_history;
	stringlist_t *my_alias;
	char **environ;
	int isenvchange;
	int my_status;

	char **cmdBuffer;
	int cmdBufferTybe;
	int rfd;
	int histnum;
} infolist_t;

#define initialInformatio \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct Builtin_Comands - ....
 * @flag: ...
 * @function: ....
 */
typedef struct Builtin_Comands
{
	char *flag;
	int (*function)(infolist_t *);
} stracOfBuildIn;

int SL(infolist_t *, char **);
int findBuiltinCom(infolist_t *);
void chkps(infolist_t *);
void fkthrd(infolist_t *);
int iscommand(infolist_t *, char *);
char *cpchar(char *, int, int);
char *fpth(infolist_t *, char *, char *);
void Printstrer(char *);
int erprchar(char);
int WFileDescreptor(char c, int fileDes);
<<<<<<< HEAD
int charsCount(char *string, int fileDes);
int getStringLength(char *);
int compareStrings(char *, char *);

=======
int chcnt(char *string, int fileDes);
int strl(char *);
int cmpstr(char *, char *);
>>>>>>> ce8ad8bdd0dffac4a2da261f41ca5ba9c1ab5ac2
char *startsWith(const char *, const char *);
char *concatenetStrings(char *, char *);
char *StringCopy(char *, char *, int);
char *concatenatesStrings(char *, char *, int);
char *locateChar(char *, char);
char **SplitString2(char *, char);
char *copyStrings(char *, char *);
char *duplcatString(const char *);
<<<<<<< HEAD

void Puts(char *);

int PutCharacter(char);

=======
void pts(char *);
int ptchr(char);
>>>>>>> ce8ad8bdd0dffac4a2da261f41ca5ba9c1ab5ac2
char **SplitString(char *, char *);
char *fillMemoryWith(char *, char, unsigned int);

void free_func(char **);

void *reAllocat(void *, unsigned int, unsigned int);

int free_ptrs(void **);
int _isinter(infolist_t *);
int _isdelim(char, char *);
int _isalpha(int);
int str_int(char *);
int str_to_int(char *);
void _errpr(infolist_t *, char *);

int des_pr(int, int);

char *convert_number(long int, int, int);

void re_co(char *);
int ex_eml(infolist_t *);
int cd_eml(infolist_t *);
int h_eml(infolist_t *);
int his_eml(infolist_t *);
int al_eml(infolist_t *);
ssize_t _get_in(infolist_t *);
int get_nl(infolist_t *, char **, size_t *);
void h_sig(int);
void info_clear(infolist_t *);
void info_set(infolist_t *, char **);
void info_free(infolist_t *, int);

char *getEnv(infolist_t *, const char *);

int _env_mine(infolist_t *);
int _set_env(infolist_t *);
int _unset_env(infolist_t *);
int _envlist_pop(infolist_t *);

char **our_environ(infolist_t *);

int _environ_rem(infolist_t *, char *);
int _envvarinit(infolist_t *, char *, char *);

char *getFileHistory(infolist_t *infolist);

int his_wr(infolist_t *infolist);
int his_r(infolist_t *infolist);
int his_listb(infolist_t *infolist, char *mybuff, int linecount);
int his_renum(infolist_t *infolist);

stringlist_t *ADDnode(stringlist_t **, const char *, int);
stringlist_t *ADDnodeEn(stringlist_t **, const char *, int);

size_t _strlistpr(const stringlist_t *);
int node_del(stringlist_t **, unsigned int);
void _listfree(stringlist_t **);
size_t _listlen(const stringlist_t *);

char **listToStrings(stringlist_t *);

size_t _elelist(const stringlist_t *);

stringlist_t *nodeStartWith(stringlist_t *, char *, char);

ssize_t node_index(stringlist_t *, stringlist_t *);
int _chainme(infolist_t *, char *, size_t *);
void _chainchecker(infolist_t *, char *, size_t *, size_t, size_t);
int _aliesrep(infolist_t *);
int _varreps(infolist_t *);
int _strrep(char **, char *);


#endif
