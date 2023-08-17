#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * get_builtin - All built-in function
 * @params: Pointer to param_t
 * Return: Built-in function pionter. NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
