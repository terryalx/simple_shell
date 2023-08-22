#include "shell.h"

#define _GNU_SOURCE
#define BUFFER_SIZE 4096

/**
 * main - entry point for simple shell
 * @argc: argument count
 * @argv: Null terminated argument list
 * @env: Null terminated environment variables list
 * Return: 0 on success
 */
int process_string(param_t *params)
{
    char *state = NULL;
    int arg_count = 0;
    char *token;

    if (!params->nextCommand)
        return 0;

    token = token_(params->nextCommand, " \t\r\n", &state);

    while (token != NULL)
    {
        if (token[0] == '$' && token[1] != '\0')
        {
            char *var_name = token + 1; 
            char *var_value = _getenv(var_name, params);
            if (var_value)
            {
                params->args[arg_count] = str_duplicate(var_value);
                free(var_value);
            }
            else
            {
                __write_error__(params, "Undefined environment variable");
                return -1;
            }
        }
        else
        {
            params->args[arg_count] = str_duplicate(token);
        }

        if (params->args[arg_count] == NULL)
        {
            __write_error__(params, "Memory allocation error");
            return -1;
        }

        arg_count++;
        token = token_(NULL, " \t\r\n", &state);
    }

    params->args[arg_count] = NULL;

    return arg_count;
}
