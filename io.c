#include "shell.h"


/**
 * getFileHistory - ...
 * @infolist: ...
 * Return: ...
 */
char *getFileHistory(infolist_t *infolist)
{
	char *buffer, *directo;

	directo = getEnv(infolist, "HOME=");
	if (!directo)
		return (NULL);

	buffer = malloc(sizeof(char) * (getStringLength(directo) +
	getStringLength(fileHistory) + 2));
	if (!buffer)
		return (NULL);

	buffer[0] = 0;

	copyStrings(buffer, directo);
	concatenetStrings(buffer, "/");

	concatenetStrings(buffer, fileHistory);
	return (buffer);
}

/**
 * his_wr - ...
 * @infolist: ...
 * Return: success 0
 */
int his_wr(infolist_t *infolist)
{
	ssize_t fileDes;
	char *file_n = getFileHistory(infolist);
	stringlist_t *my_node = NULL;

	if (!file_n)
		return (-1);

	fileDes = open(file_n, O_CREAT | O_TRUNC | O_RDWR, 0644);

	free(file_n);

	if (fileDes == -1)
		return (-1);

	for (my_node = infolist->my_history; my_node; my_node = my_node->next_node)
	{
		charsCount(my_node->string, fileDes);

		WFileDescreptor('\n', fileDes);
	}
	WFileDescreptor(bufferFlush, fileDes);
	close(fileDes);
	return (1);
}

/**
 * his_r - ...
 * @infolist: ...
 * Return: ...
 */
int his_r(infolist_t *infolist)
{
	int x, end = 0, l_num = 0;
	ssize_t fileDes, read_l, file_s = 0;
	struct stat fileStat;
	char *buffer = NULL, *file_n = getFileHistory(infolist);

	if (!file_n)
		return (0);

	fileDes = open(file_n, O_RDONLY);
	free(file_n);
	if (fileDes == -1)
		return (0);
	if (!fstat(fileDes, &fileStat))
		file_s = fileStat.st_size;
	if (file_s < 2)
		return (0);
	buffer = malloc(sizeof(char) * (file_s + 1));
	if (!buffer)
		return (0);
	read_l = read(fileDes, buffer, file_s);
	buffer[file_s] = 0;
	if (read_l <= 0)
		return (free(buffer), 0);
	close(fileDes);
	for (x = 0; x < file_s; x++)
		if (buffer[x] == '\n')
		{
			buffer[x] = 0;
			his_listb(infolist, buffer + end, l_num++);
			end = x + 1;
		}
	if (end != x)
		his_listb(infolist, buffer + end, l_num++);
	free(buffer);

	infolist->histnum = l_num;
	while (infolist->histnum-- >= maxHistory)
		node_del(&(infolist->my_history), 0);
	his_renum(infolist);
	return (infolist->histnum);
}

/**
 * his_listb - ...
 * @infolist: ...
 * @buffer: ...
 * @l_num: ...
 * Return: 0 success
 */
int his_listb(infolist_t *infolist, char *buffer, int l_num)
{
	stringlist_t *my_node = NULL;

	if (infolist->my_history)
		my_node = infolist->my_history;

	ADDnodeEn(&my_node, buffer, l_num);

	if (!infolist->my_history)
		infolist->my_history = my_node;
	return (0);
}

/**
 * his_renum - ...
 * @infolist: ...
 * Return: ...
 */
int his_renum(infolist_t *infolist)
{
	stringlist_t *my_node = infolist->my_history;
	int x = 0;

	while (my_node)
	{
		my_node->number = x++;
		my_node = my_node->next_node;
	}
	return (infolist->histnum = x);
}
