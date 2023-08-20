#include "shell.h"

/**
 * run_command - searches path directories for a command and executes it
 * @params: parameters
 */
void run_command(param_t *params)
{
    char *exeFile = NULL;
    pid_t pid;

    void (*buildin)(param_t *);

    buildin = get_builtin(params);

    if (buildin)
    {
        buildin(params);
        return;
    }

    exeFile = search_path_for_command(params);
    if (!exeFile)
    {
        return;
    }

    pid = fork();
    if (pid < 0)
    {
        free_params(params);
        free(exeFile);
        exit(98);
    }
    else if (pid == 0)
    {
        if (execve(exeFile, params->args, params->env) == -1)
        {
            perror("execve"); // Print an error message if execve fails
            free_params(params);
            free(exeFile);
            exit(127);
        }
    }
    else
    {
        wait(&params->status);
        params->status = WEXITSTATUS(params->status);
        free(exeFile);
    }
}
