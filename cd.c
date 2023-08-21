#include "shell.h"

void set_oldpwd(param_t *params, char **tmpArgs);
void set_pwd(param_t *params, char **tmpArgs);

/**
 * _cd - change current working directory
 * @params: shell parameters
 * Return: void
 */
void _cd(param_t *params)
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
		write_error(params, "can't cd to ");
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
 * set_oldpwd - set OLDPWD to the current PWD
 * @params: shell parameters
 * @tmpArgs: temporary arguments
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
 * set_pwd - set PWD to the target working directory
 * @params: shell parameters
 * @tmpArgs: temporary arguments
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
