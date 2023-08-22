#include "shell.h"

void set_oldpwd(param_t *params, char **tmpArgs);
void set_pwd(param_t *params, char **tmpArgs);

/**
 * change_directory - Change Current Working Directory
 * @params: Pointer to the shell parameters structure.
 *
 * Change the current working directory of the shell.
 * Supports three modes of operation:
 * 1. No arguments: Change to the user's home directory.
 * 2. "-" argument: Change to the previous working directory.
 * 3. Directory path: Change to the specified directory.
 *
 * Return: void
 */
void change_directory(param_t *params)
{
	char *target = NULL;
	char **tmpArgs = NULL, **originArgs = NULL;
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
		if (!string_compare(params->args[1], "-"))
		{
			target = _getenv("OLDPWD", params);
			if (!target)
			{
				params->status = 0;
				target = _getenv("PWD", params);
				my_printf("%s\n", target);
				free(target);
				return;
			}
			my_printf("%s\n", target);
		}
		else
		{
			params->status = 2;
			my_printf("%s: %d: cd: Illegal option %c%c\n",
					params->argv[0], params->lineCount,
					'-', params->args[1][1]);
			return;
		}
	}
	else
	{
		target = str_duplicate(params->args[1]);
		if (!target)
		{
			write(STDERR_FILENO, "cd target malloc error\n", 18);
			exit(-1);
		}
	}
	i = chdir(target);
	if (i)
	{
		__write_error__(params, "can't cd to ");
		write(STDERR_FILENO, target, _strlen(target));
		write(STDERR_FILENO, "\n", 1);
		params->status = 0;
		free(target);
		return;
	}
	free(target);
	tmpArgs = malloc(sizeof(char *) * 3);
	if (!tmpArgs)
		exit(-1);
	originArgs = params->args;
	params->args = tmpArgs;
	params->tokCount = 3;
	set_oldpwd(params, tmpArgs);
	set_pwd(params, tmpArgs);
	free(tmpArgs);
	params->args = originArgs;
}

/**
 * set_oldpwd - Set OLDPWD Environment Variable
 * @params: Pointer to the shell parameters structure.
 * @tmpArgs: Temporary arguments array.
 *
 * Sets the OLDPWD environment variable to the current PWD.
 *
 * Return: void
 */
void set_oldpwd(param_t *params, char **tmpArgs)
{
	tmpArgs[0] = str_duplicate("setenv");
	tmpArgs[1] = str_duplicate("OLDPWD");
	if (!tmpArgs[0] || !tmpArgs[1])
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 18);
		free_params(params);
		exit(-1);
	}
	tmpArgs[2] = _getenv("PWD", params);
	set_or_update_environment_variable(params);
}

/**
 * set_pwd - Set PWD Environment Variable
 * @params: Pointer to the shell parameters structure.
 * @tmpArgs: Temporary arguments array.
 *
 * Sets the PWD environment variable to the target working directory.
 *
 * Return: void
 */
void set_pwd(param_t *params, char **tmpArgs)
{
	char cwd[1024];

	tmpArgs[0] = str_duplicate("setenv");
	tmpArgs[1] = str_duplicate("PWD");
	tmpArgs[2] = str_duplicate(getcwd(cwd, 1024));
	if (!tmpArgs[0] || !tmpArgs[1] || !tmpArgs[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 18);
		free_params(params);
		exit(-1);
	}
	set_or_update_environment_variable(params);
}
