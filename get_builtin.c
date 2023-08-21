#include "shell.h"

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
		{"setenv", set_or_update_environment_variable},
		{"cd", _cd},
		{"unsetenv", str_length},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!string_compare(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
