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

int shellLoob(infolist_t *, char **);
int findBuiltinCom(infolist_t *);
void cheackPasses(infolist_t *);
void forkThread(infolist_t *);
int isCMD(infolist_t *, char *);
char *duplCharacters(char *, int, int);
char *findPath(infolist_t *, char *, char *);
void errPrintStr(char *);
int errPrintChar(char);
int WFileDescreptor(char c, int fileDes);
int charsCount(char *string, int fileDes);
int getStringLength(char *);
int compareStrings(char *, char *);
char *startsWith(const char *, const char *);
char *concatenetStrings(char *, char *);
char *StringCopy(char *, char *, int);
char *concatenatesStrings(char *, char *, int);
char *locateChar(char *, char);
char **SplitString2(char *, char);
char *copyStrings(char *, char *);
char *duplcatString(const char *);
void Puts(char *);
int PutCharacter(char);
char **SplitString(char *, char *);
char *fillMemoryWith(char *, char, unsigned int);
void freeFun(char **);
void *reAllocat(void *, unsigned int, unsigned int);
int freePointers(void **);
int IsInteractive(infolist_t *);
int IsDelimeter(char, char *);
int ISAlphabetic(int);
int StrToInt(char *);
int StringToInteger(char *);
void PrintError(infolist_t *, char *);
int printDescriptor(int, int);
char *convert_number(long int, int, int);
void re_comm(char *);
int exitEmulator(infolist_t *);
int cdEmulator(infolist_t *);
int helpEmulator(infolist_t *);
int historyEmulator(infolist_t *);
int aliasEmulator(infolist_t *);
ssize_t getInput(infolist_t *);
int getNextLine(infolist_t *, char **, size_t *);
void hamdelSigin(int);
void clearInformation(infolist_t *);
void setInformation(infolist_t *, char **);
void freeInformation(infolist_t *, int);
char *getEnv(infolist_t *, const char *);
int my_env(infolist_t *);
int mySetEnv(infolist_t *);
int unSetEnv(infolist_t *);
int populateEnvList(infolist_t *);
char **our_environ(infolist_t *);
int remov_environ(infolist_t *, char *);
int init_env_var(infolist_t *, char *, char *);
char *getFileHistory(infolist_t *infolist);
int w_history(infolist_t *infolist);
int r_history(infolist_t *infolist);
int buildHistoryList(infolist_t *infolist, char *mybuff, int linecount);
int renumberHistory(infolist_t *infolist);
stringlist_t *ADDnode(stringlist_t **, const char *, int);
stringlist_t *ADDnodeEn(stringlist_t **, const char *, int);
size_t printListString(const stringlist_t *);
int deletNode(stringlist_t **, unsigned int);
void freeList(stringlist_t **);
size_t listLength(const stringlist_t *);
char **listToStrings(stringlist_t *);
size_t elementList(const stringlist_t *);
stringlist_t *nodeStartWith(stringlist_t *, char *, char);
ssize_t nodeIndex(stringlist_t *, stringlist_t *);
int isChain(infolist_t *, char *, size_t *);
void checkChain(infolist_t *, char *, size_t *, size_t, size_t);
int replaceAlies(infolist_t *);
int replaVars(infolist_t *);
int replaStr(char **, char *);


#endif
