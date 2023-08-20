#include "shell.h"

/**
 * process_string - process the next command into string tokens
 * @params: parameters
 *
 * Return: number of tokens
 */
int process_string(param_t *params)
{
	char *token = NULL, *state = NULL;
	char *alias = NULL, *state_2 = NULL, *val;
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
		alias = _strdup(node->value);
		if (!alias)
		{
			write(STDERR_FILENO,
			      "alias expansion malloc error\n", 18);
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
	else
		(params->args)[(params->tokCount)++] = token;
	token = token_(params->nextCommand, " \n\t", &state);
	params->args[params->tokCount++] = token;
	while (token)
	{
		token = token_(params->nextCommand, " \n\t", &state);
		(params->args)[(params->tokCount)++] = token;
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
	return (params->tokCount - 1);
}
