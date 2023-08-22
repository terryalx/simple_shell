#include "shell.h"

/**
 * find_builtin_function - Find the appropriate built-in function based on the provided command.
 * @params: Pointer to the param_t structure.
 *
 * This function takes a command as input and returns a pointer to the corresponding
 * built-in function if it matches one of the built-in commands. If no match is found,
 * it returns NULL.
 *
 * @params: Pointer to the param_t structure containing the command and arguments.
 *
 * Return: Pointer to the matched built-in function, or NULL if not found.
 */
void (*find_builtin_function(param_t *params))(param_t *)
{
    static const op_t ops[] = {
        {"cd", change_directory},
        {"alias", _alias},
        {"exit", myExit},
        {"clear", clear_terminal_screen},
        {"env", _printenv},
        {"setenv", set_or_update_environment_variable},
        {"unsetenv", remove_environment_variable},
        {NULL, NULL}
    };

    const op_t *op;

    for (op = ops; op->name != NULL; op++)
    {
        if (!string_compare(params->args[0], op->name))
        {
            return op->func;
        }
    }

    return NULL;
}
