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

    token = token_(params->nextCommand, " \n\t", &state);
    if (!token)
    {
        params->tokCount = 0;
        return (0);
    }

    list_t *node = get_node(params->alias_head, token);
    if (node != NULL)
    {
        handle_alias(params, token, node);
    }
    else
    {
        handle_regular(params, token, state);
    }

    return (params->tokCount - 1);
}

/**
 * handle_alias - Handle token expansion for alias
 * @params: parameters
 * @token: current token
 * @node: alias node
 *
 * This function expands an alias token and stores the resulting tokens
 * in the 'params->args' array.
 */
static void handle_alias(param_t *params, char *token, list_t *node)
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

/**
 * handle_regular - Handle regular token processing
 * @params: parameters
 * @token: current token
 * @state: tokenization state
 *
 * This function processes regular tokens and stores them in the 'params->args' array.
 */
static void handle_regular(param_t *params, char *token, char *state)
{
    while (token)
    {
        (params->args)[(params->tokCount)++] = token;
        token = token_(params->nextCommand, " \n\t", &state);

        if (params->tokCount == params->argsCap)
        {
            params->argsCap += 10;
            params->args = _realloc(params->args,
                                    params->argsCap - 10,
                                    params->argsCap);
            if (!(params->args))
            {
                write(STDERR_FILENO, "realloc error\n", 14);
                free_params(params);
                exit(-1);
            }
        }
    }
}
