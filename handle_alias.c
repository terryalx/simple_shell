#include "shell.h"

/**
 * handle_alias - Handle token expansion for alias
 * @params: parameters
 * @token: current token
 * @node: alias node
 *
 * This function expands an alias token and stores the resulting tokens
 * in the 'params->args' array.
 */
void handle_alias(param_t *params, char *token, list_t *node)
{
    char *alias = NULL, *state_2 = NULL, *val;

    free(token);
    token = NULL;
    alias = _strdup(node->value);
    if (!alias)
    {
        write(STDERR_FILENO, "alias expansion malloc error\n", 30);
        free_params(params);
        exit(-1);
    }
    val = token_(alias, " \n\t", &state_2);
    (params->args)[(params->tokCount)++] = val;

    while (val)
    {
        val = token_(alias, " ", &state_2);
        (params->args)[(params->tokCount)++] = val;
    }
    free(alias);
}
