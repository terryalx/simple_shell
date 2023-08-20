#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * process_string - process the next command into string tokens
 * @params: parameters
 *
 * Return: number of tokens
 */
int process_string(param_t *params)
{
	char *token = NULL;
	char *state = NULL;
	char *token_val = NULL;
	list_t *node;

	token = token_(params->nextCommand, " \n\t", &state);
	if (!token)
	{
		params->tokCount = 0;
		return (0);
	}

	node = get_node(params->alias_head, token);
	if (node != NULL)
	{
		free(token);
		token = NULL;
		token_val = _strdup(node->val);
		if (!token_val)
		{
			perror("alias expansion malloc error");
			free_params(params);
			exit(EXIT_FAILURE);
		}
		params->args[params->tokCount++] = token_val;
		while (token_val)
		{
			token_val = token_(token_val, " ", &state);
			params->args[params->tokCount++] = token_val;
		}
		free(token_val);
	}
	else
		params->args[params->tokCount++] = token;

	token = token_(params->nextCommand, " \n\t", &state);
	params->args[params->tokCount++] = token;
	while (token)
	{
		token = token_(params->nextCommand, " \n\t", &state);
		params->args[params->tokCount++] = token;
		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args, params->argsCap - 10, params->argsCap);
			if (!params->args)
			{
				perror("realloc error");
				free_params(params);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (params->tokCount - 1);
}
