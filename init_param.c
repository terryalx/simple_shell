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
	unsigned int i;

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
	for (i = 0; i < BUFFER_SIZE; i++)
		params->buffer[i] = 0;

	params->args = malloc(sizeof(char *) * params->argsCap);
	if (!(params->args))
	{
		free(params->buffer);
		free(params);
		exit(-1);
	}
	for (i = 0; i < params->argsCap; i++)
		params->args[i] = NULL;

	params->env_head = NULL;
	for (i = 0; env[i]; i++)
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

	params->alias_head = NULL;

	return (params);
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
