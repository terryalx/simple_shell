#include "shell.h"

void handle_cd_options(param_t *params)
char *get_cd_target(param_t *params)
int change_directory(char *target, param_t *params)
void update_environment_variables(param_t *params, char *target)
void handle_cd_error(char *target, param_t *params)
/**
 * _cd - Change the current working directory.
 *
 * This function handles changing the current working directory based on
 * the provided arguments in the shell parameters.
 *
 * @params: Shell parameters.
 *
 * Return: void.
 */
void _cd(param_t *params)
{
    char *target = NULL;
    char **tmpArgs = NULL, **originArgs = NULL;

    if (params->tokCount == 1)
    {
        target = _getenv("HOME", params);
        if (!target)
        {
            params->status = 0;
            return;
        }
    }
    else if (params->args[1][0] == '-')
    {
        handle_cd_options(params);
    }
    else
    {
        target = get_cd_target(params);
    }

    if (change_directory(target, params) == -1)
    {
        handle_cd_error(target, params);
        return;
    }

    set_or_update_environment_variable(params, target);

    params->args = originArgs;
}

/**
 * handle_cd_options - Handle special CD options.
 *
 * This function handles special options for the CD command.
 *
 * @params: Shell parameters.
 *
 * Return: void.
 */
void handle_cd_options(param_t *params)
{
    if (!string_compare(params->args[1], "-"))
    {
        char *target = _getenv("OLDPWD", params);
        if (!target)
        {
            params->status = 0;
            target = _getenv("PWD", params);
            my_printf("%s\n", target);
            free(target);
            return;
        }
        my_printf("%s\n", target);
    }
    else
    {
        params->status = 2;
        my_printf("%s: %d: cd: Illegal option %c%c\n",
                  params->argv[0], params->lineCount,
                  '-', params->args[1][1]);
    }
}

/**
 * get_cd_target - Get the CD target based on shell parameters.
 *
 * This function returns the target directory for the CD command.
 *
 * @params: Shell parameters.
 *
 * Return: A dynamically allocated string containing the target directory,
 *         or NULL on failure.
 */
char *get_cd_target(param_t *params)
{
    char *target = str_duplicate(params->args[1]);
    if (!target)
    {
        write(STDERR_FILENO, "cd target malloc error\n", 18);
        exit(-1);
    }
    return target;
}

/**
 * change_directory - Change the current working directory.
 *
 * This function changes the current working directory to the specified target.
 *
 * @target: The target directory.
 * @params: Shell parameters.
 *
 * Return: 0 on success, -1 on failure.
 */
int change_directory(char *target, param_t *params)
{
    int i = chdir(target);
    free(target);
    if (i)
    {
        write_error(params, "can't cd to ");
        write(STDERR_FILENO, params->args[1], _strlen(params->args[1]));
        write(STDERR_FILENO, "\n", 1);
        params->status = 0;
        return -1;
    }
    return 0;
}

/**
 * update_environment_variables - Update environment variables after CD.
 *
 * This function updates the OLDPWD and PWD environment variables
 * after changing the current working directory.
 *
 * @params: Shell parameters.
 * @target: The target directory.
 *
 * Return: void.
 */
void update_environment_variables(param_t *params, char *target)
{
    char **tmpArgs = malloc(sizeof(char *) * 3);
    if (!tmpArgs)
    {
        write(STDERR_FILENO, "cd environment variables malloc error\n", 37);
        free_params(params);
        exit(-1);
    }
    
    tmpArgs[0] = str_duplicate("setenv");
    tmpArgs[1] = str_duplicate("OLDPWD");
    tmpArgs[2] = _getenv("PWD", params);
    set_or_update_environment_variable(params);
    free(tmpArgs[0]);
    free(tmpArgs[1]);
    free(tmpArgs[2]);
    free(tmpArgs);

    tmpArgs = malloc(sizeof(char *) * 3);
    if (!tmpArgs)
    {
        write(STDERR_FILENO, "cd environment variables malloc error\n", 37);
        free_params(params);
        exit(-1);
    }
    tmpArgs[0] = str_duplicate("setenv");
    tmpArgs[1] = str_duplicate("PWD");
    tmpArgs[2] = str_duplicate(getcwd(NULL, 0));
    set_or_update_environment_variable(params);
    free(tmpArgs[0]);
    free(tmpArgs[1]);
    free(tmpArgs[2]);
    free(tmpArgs);
}

/**
 * handle_cd_error - Handle CD command error.
 *
 * This function handles errors encountered during the CD command.
 *
 * @target: The target directory.
 * @params: Shell parameters.
 *
 * Return: void.
 */
void handle_cd_error(char *target, param_t *params)
{
    write_error(params, "can't cd to ");
    write(STDERR_FILENO, target, _strlen(target));
    write(STDERR_FILENO, "\n", 1);
    params->status = 0;
    free(target);
}
