#include "shell.h"

/**
 * handle_regular - Handle regular token processing
 * @params: parameters
 * @token: current token
 * @state: tokenization state
 *
 * This function processes regular tokens and stores them in the 'params->args' array.
 */
void handle_regular(param_t *params, char *token, char *state)
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
