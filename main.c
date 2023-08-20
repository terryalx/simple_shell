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
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	param_t *params = NULL;
	int cond = -2, status;
	unsigned int i;
	char *state = NULL;
	size_t size = BUFFER_SIZE;

	params = init_param(argv, env);
	if (!params)
		exit(-1);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		if (cond == -1)
		{
			status = params->status;
			_printf("$ :\n");
			free_params(params);
			return (status);
		}
		for (i = 0; i < BUFFER_SIZE; i++)
			(params->buffer)[i] = 0;
		params->tokCount = 0;
		if (isatty(STDIN_FILENO))
			_printf("$: ");
		cond = getline(&params->buffer, &size, stdin);
		params->lineCount++;
		if (cond == -1 && _strlen(params->buffer) == 0)
		{
			status = params->status;
			free_params(params);
			return (status);
		}
		state = NULL;
		params->nextCommand = token_(params->buffer, ";\n", &state);
		while (params->nextCommand)
		{
			params->tokCount = process_string(params);
			if (params->tokCount == 0)
				break;
			run_command(params);
			for (i = 0; i < params->argsCap; i++)
			{
				free(params->args[i]);
				params->args[i] = NULL;
			}
			params->tokCount = 0;
			free(params->nextCommand);
			params->nextCommand = token_(params->buffer, ";\n",
						      &state);
		}
	}
}
