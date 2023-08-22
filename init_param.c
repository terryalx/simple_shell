#include "shell.h"

#define _GNU_SOURCE
#define BUFFER_SIZE 4096

/**
 * allocate_param - Allocate memory for a new param_t structure.
 * @argv: Command line argument.
 * @env: Environment variables.
 * Return: Pointer to the newly allocated param_t structure or NULL on failure.
 */
static param_t *allocate_param(char **argv, char **env)
{
    param_t *params = malloc(sizeof(*params));

    if (!params)
        return (NULL);

    params->argsCap = 10;
    params->lineCount = 0;
    params->tokCount = 0;
    params->status = 0;
    params->argv = argv;
    params->nextCommand = NULL;

    params->buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (!(params->buffer))
    {
        free(params);
        exit(-1);
    }
    for (unsigned int i = 0; i < BUFFER_SIZE; i++)
        params->buffer[i] = 0;

    params->args = malloc(sizeof(char *) * params->argsCap);
    if (!(params->args))
    {
        free(params->buffer);
        free(params);
        exit(-1);
    }
    for (unsigned int i = 0; i < params->argsCap; i++)
        params->args[i] = NULL;

    params->env_head = NULL;
    params->alias_head = NULL;

    return params;
}

/**
 * populate_environment - Populate environment variables in param_t structure.
 * @params: Pointer to the param_t structure.
 * @env: Environment variables.
 */
static void populate_environment(param_t *params, char **env)
{
    char *eqs = NULL;

    for (unsigned int i = 0; env[i]; i++)
    {
        eqs = find_character_in_string(env[i], '=');
        *eqs = '\0';

        params->env_head = prepend_list_node(&(params->env_head),
                                             env[i], eqs + 1);

        if (!(params->env_head))
        {
            free(params->buffer);
            free(params->args);
            free_list(params->env_head);
            free(params);
            exit(-1);
        }
    }
}

/**
 * init_param - Initialize params structure for the shell program.
 * @argv: Command line argument.
 * @env: Environment variables.
 * Return: Pointer to the initialized param_t structure or NULL on failure.
 */
param_t *init_param(char **argv, char **env)
{
    param_t *params = allocate_param(argv, env);

    if (!params)
        return (NULL);

    populate_environment(params, env);

    return (params);
}
