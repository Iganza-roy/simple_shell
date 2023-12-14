#include "shell.h"

/**
 * user_prompt - ...
 * @void: ...
 */
void user_prompt(in *inf)
{
	if (inf->is_itrv)
		_printme("$ ");
}
