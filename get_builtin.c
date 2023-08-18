#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * get_builtin - Get the built-in function based on the input parameters
 * @input_params: Pointer to the input parameters
 * Return: Pointer to the built-in function. NULL if not found.
 */
typedef void (*builtin_func_t)(param_t *);

/**
 * get_builtin - Get the built-in function based on the input parameters
 * @input_params: Pointer to the input parameters
 *
 * Return: Pointer to the built-in function. NULL if not found.
 */
builtin_func_t get_builtin(param_t *input_params)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", clear_screen},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *current_op = ops;

	while (current_op->name)
	{
		if (!_strcmp(input_params->args[0], current_op->name))
		{
			return (current_op->func);
		}
		current_op++;
	}
	return (NULL);
}
