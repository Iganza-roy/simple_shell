#include "shell.h"

/**
 * get_path - ...
 * @cmd: ...
 */
/*void get_path(char *cmd)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		perror("Can't get path\n");
		exit(EXIT_FAILURE);
	}

	char *tkn;
	char *other = path;
	int got_cmd = 0;

	while ((tkn = strtok_r(other, ":", &other)) != NULL)
	{
		char cmd_path[MAX_PATH_LEN];

		snprintf(cmd_path, sizeof(cmd_path), "%s%s", tkn, cmd);

		if (access(cmd_path, X_OK) == 0)
		{
			got_cmd = 1;
			execute_cmd(cmd);
			break;
		}
	}

	if (!got_cmd)
	{
		_printme("Cant find command: %s\n", cmd);
	}
}*/
