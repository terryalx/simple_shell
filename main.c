#include "shell.h"
#define _GNU_SOURCE
#define BUFFER_SIZE 4096

/**
 * main - entry point for simple shell
 * @argc: argument count
 * @argv: Null terminated argument list
 * @env: Null terminated environment variables list
 * 
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
            my_printf("$ :\n");
            free_params(params);
            return (status);
        }

        /* ... Read input and process logic ... */

        if (params->tokCount != 0 && my_strcmp(params->args[0], "exit") == 0)
        {
            if (params->tokCount > 2)
            {
                my_write_error(params, "exit: too many arguments\n");
                params->status = 2;
            }
            else if (params->tokCount == 1)
            {
                free_params(params);
                exit(0);
            }
            else
            {
                if (my_validNum(params->args[1]))
                {
                    status = my_atoi(params->args[1]);
                    free_params(params);
                    exit(status);
                }
                else
                {
                    my_write_error(params, "exit: Illegal number: ");
                    my_write(STDERR_FILENO, params->args[1], my_strlen(params->args[1]));
                    my_write(STDERR_FILENO, "\n", 1);
                    params->status = 2;
                }
            }
        }

        /* ... Continue processing other commands ... */
    }

    return (0);
}
