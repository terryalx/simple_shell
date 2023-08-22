#include "shell.h"

/**
 * execute_external_command - Searches path
 * directories for a command and executes it.
 * @params: Parameters containing the command
 * to be executed.
 */
void execute_external_command(param_t *params)
{
	char *exeFile = NULL;
	pid_t pid;
	void (*buildin)(param_t *);

	buildin = find_builtin_function(params);
	if (buildin)
	{
		buildin(params);
		return;
	}

	exeFile = get_file(params);
	if (!exeFile)
	{
		return;
	}

	pid = fork();
	if (pid < 0)
	{
		free_params(params);
		exit(98);
	}
	else if (pid == 0)
	{
		execve(exeFile, params->args, NULL);
	}
	else
	{
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(exeFile);
	}
}
