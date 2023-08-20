#include "shell.h"

/**
 * split_command_into_tokens - Split the next command into string tokens
 * @params: parameters
 *
 * This function splits the given command into tokens and stores them in
 * the 'params->args' array.
 *
 * Return: number of tokens
 */
int split_command_into_tokens(param_t *params)
{
    char *token = NULL, *state = NULL;
    list_t *node;

    params->tokCount = 0;

    token = token_(params->nextCommand, " \n\t", &state);
    while (token)
    {
        node = get_node(params->alias_head, token);
        if (node != NULL)
        {
            handle_alias(params, token, node);
        }
        else
        {
            handle_regular(params, token, state);
        }

        token = token_(params->nextCommand, " \n\t", &state);
    }

    return (params->tokCount);
}
