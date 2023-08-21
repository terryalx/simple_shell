#include "shell.h"

/**
 * get_builtin - Get the built-in function based on the input parameters
 * @input_params: Pointer to the input parameters
 *
 * Return: Pointer to the built-in function. NULL if not found.
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
		if (!string_compare(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
