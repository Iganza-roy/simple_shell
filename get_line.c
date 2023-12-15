#include "shell.h"

/**
 * inputBuffer - ...
 * @infolist: ...
 * @mybuff: ...
 * @mylen: ...
 * Return: ...
 */
ssize_t inputBuffer(infolist_t *infolist, char **mybuff, size_t *mylen)
{
	ssize_t x = 0;
	size_t p_lenth = 0;

	if (!*mylen)
	{
		free(*mybuff);
		*mybuff = NULL;
		signal(SIGINT, h_sig);
#if useGetLine/* extract from getline */
		x = getline(mybuff, &p_lenth, stdin);/*from <stdio>*/
#else/* read from stdin */
		x = get_nl(infolist, mybuff, &p_lenth);
#endif
		if (x > 0)
		{
			if ((*mybuff)[x - 1] == '\n')
			{
				(*mybuff)[x - 1] = '\0';
				x--;
			}
			infolist->linenumflag = 1;
			re_co(*mybuff);
			his_listb(infolist, *mybuff, infolist->histnum++);
			{
				*mylen = x;
				infolist->cmdBuffer = mybuff;
			}
		}
	}
	return (x);
}

/**
 * _get_in - ...
 * @infolist: ...
 * Return: ...
 */
ssize_t _get_in(infolist_t *infolist)
{
	static char *mybuff;
	static size_t iter, y, mylen;
	ssize_t x = 0;
	char **p_beff = &(infolist->argument), *p;

	PutCharacter(bufferFlush);
	x = inputBuffer(infolist, &mybuff, &mylen);
	if (x == -1)
		return (-1);
	if (mylen)
	{
		y = iter;
		p = mybuff + iter;

		_chainchecker(infolist, mybuff, &y, iter, mylen);
		while (y < mylen)
		{
			if (_chainme(infolist, mybuff, &y))
				break;
			y++;
		}

		iter = y + 1;
		if (iter >= mylen)
		{
			iter = mylen = 0;
			infolist->cmdBufferTybe = cmdNormal;
		}

		*p_beff = p;
		return (getStringLength(p));
	}

	*p_beff = mybuff;
	return (x);
}

/**
 * readBuffer - ...
 * @infolist: ...
 * @mybuff: ...
 * @iter: ...
 *
 * Return: ...
 */
ssize_t readBuffer(infolist_t *infolist, char *mybuff, size_t *iter)
{
	ssize_t x = 0;

	if (*iter)
		return (0);
	x = read(infolist->rfd, mybuff, readBufferSize);

	if (x >= 0)
		*iter = x;
	return (x);
}

/**
 * get_nl - ...
 * @infolist: ...
 * @stoline: ...
 * @bufsize: ...
 * Return: ...
 */
int get_nl(infolist_t *infolist, char **stoline, size_t *bufsize)
{
	static char mybuff[readBufferSize];
	static size_t iter, mylen;
	size_t z;
	ssize_t x = 0, st = 0;
	char *ptr = NULL, *newPtr = NULL, *chr;

	ptr = *stoline;

	if (ptr && bufsize)
		st = *bufsize;

	if (iter == mylen)
		iter = mylen = 0;

	x = readBuffer(infolist, mybuff, &mylen);/* Read data into the buffer */
	if (x == -1 || (x == 0 && mylen == 0))/* Check for read errors or EOF */
		return (-1);


	chr = locateChar(mybuff + iter, '\n');
	z = chr ? 1 + (unsigned int)(chr - mybuff) : mylen;

	newPtr = reAllocat(ptr, st, st ? st + z : z + 1);
	if (!newPtr)
		return (ptr ? free(ptr), -1 : -1);

	if (st)
		concatenatesStrings(newPtr, mybuff + iter, z - iter);
	else
		StringCopy(newPtr, mybuff + iter, z - iter + 1);
	st += z - iter;
	iter = z;
	ptr = newPtr;

	if (bufsize)
		*bufsize = st;
	*stoline = ptr;
	return (st);
}

/**
 * h_sig - ...
 * @sig_num: ...
 */
void h_sig(__attribute__((unused))int sig_num)
{
	Puts("\n");
	Puts("$ ");
	PutCharacter(bufferFlush);

}
