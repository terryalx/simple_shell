#include "shell.h"

/**
 * run_command - searches path directories for command and executes it
 * @params: parameters
 */
void run_command(param_t *params)
{
	char *exeFile = NULL;
	pid_t pid;
	void (*buildin)(param_t *);

	buildin = get_builtin(params);
	if (buildin)
	{
		buildin(params);
		return;
	}
	exeFile = check_current_directory(params);
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
