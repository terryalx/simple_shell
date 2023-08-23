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

    if (!initialize_buffer(params))
        return (NULL);

    if (!initialize_args(params))
        return (NULL);

    if (!initialize_environment(params, env))
        return (NULL);

    params->alias_head = NULL;

    return (params);
}

/**
 * initialize_buffer - Initialize the buffer in the param_t structure.
 * @params: Pointer to the param_t structure.
 * Return: 1 on success, 0 on failure.
 */
static int initialize_buffer(param_t *params)
{
    params->buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (!(params->buffer))
    {
        free(params);
        exit(-1);
    }
    for (unsigned int i = 0; i < BUFFER_SIZE; i++)
        params->buffer[i] = 0;

    return (1);
}

/**
 * initialize_args - Initialize the args array in the param_t structure.
 * @params: Pointer to the param_t structure.
 * Return: 1 on success, 0 on failure.
 */
static int initialize_args(param_t *params)
{
    params->args = malloc(sizeof(char *) * params->argsCap);
    if (!(params->args))
    {
        free(params->buffer);
        free(params);
        exit(-1);
    }
    for (unsigned int i = 0; i < params->argsCap; i++)
        params->args[i] = NULL;

    return (1);
}

/**
 * initialize_environment - Populate environment variables in param_t structure.
 * @params: Pointer to the param_t structure.
 * @env: Environment variables.
 * Return: 1 on success, 0 on failure.
 */
static int initialize_environment(param_t *params, char **env)
{
    params->env_head = NULL;

    for (unsigned int i = 0; env[i]; i++)
    {
        char *eqs = find_character_in_string(env[i], '=');
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

    return (1);
}

/**
 * init_param - Initialize params structure for the shell program.
 * @argv: Command line argument.
 * @env: Environment variables.
 * Return: Pointer to the initialized param_t structure or NULL on failure.
 */
param_t *init_param(char **argv, char **env)
{
    return (allocate_param(argv, env));
}
