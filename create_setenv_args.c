#include "shell.h"
#include <stdlib.h>
#include <limits.h>

/**
 * create_setenv_args - Create an array of arguments for the setenv command
 * @command: The command name
 * @variable: The variable name
 * @value: The value to set the variable to
 *
 * Return: The array of arguments for the setenv command
 */
char **create_setenv_args(char *command, char *variable, char *value)
{
	char **args = malloc(sizeof(char *) * 4);
	if (!args)
		return (NULL);

	args[0] = _strdup(command);
	if (!args[0])
	{
		free(args);
		return (NULL);
	}

	args[1] = _strdup(variable);
	if (!args[1])
	{
		free(args[0]);
		free(args);
		return (NULL);
	}

	args[2] = _strdup(value);
	if (!args[2])
	{
		free(args[1]);
		free(args[0]);
		free(args);
		return NULL;
	}

	args[3] = NULL;

	return (args);
}
