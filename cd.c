#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _cd - change current working directory
 * @params: shell parameters
 * Return: void
 */
void _cd(param_t *params)
{
	char *target = NULL;
	char cwd[1024];
	char **tmpArgs = NULL;
	char **originArgs = NULL;
	int i;

	if (params->tokCount == 1)
	{
		target = _getenv("HOME", params);
		if (!target)
		{
			params->status = 0;
			return;
		}
	}
	else if (params->args[1][0] == '-')
	{
		handle_dash(params);
	}
	else
	{
		target = _strdup(params->args[1]);
		if (!target)
		{
			handle_malloc_error();
		}
	}

	i = chdir(target);
	if (i)
	{
		handle_chdir_error(params, target);
		return;
	}

	free(target);
	update_oldpwd(params);

	tmpArgs = create_tmp_args(params);
	setenv_oldpwd(tmpArgs[2], params);
	setenv_pwd(tmpArgs, cwd, params);

	free_tmp_args(tmpArgs);
	restore_original_args(params, originArgs);
}
