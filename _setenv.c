#include "shell.h"

/**
 * _setenv - Set or update an environment variable.
 * @params: Parameters struct.
 *
 * This function sets or updates an environment variable.
 *
 * Return: void
 */
void _setenv(param_t *params)
{
    int val = 0;
    char *tmp = NULL;
    char *name = params->args[1];
    char *value = params->args[2];

    list_t *h = params->env_head;

    if (params->tokCount != 3)
    {
        params->status = 0;
        return;
    }

    while (h)
    {
        if (string_compare(name, h->str) == 0)
        {
            tmp = h->value;
            free(tmp);
            h->value = str_duplicate(value);
            if (!h->value)
            {
                write(STDERR_FILENO, "Failed to allocate memory for environment variable: %s\n", name);
                exit(val);
            }
            h->value_length = _strlen(value);
            params->status = 0;
            return;
        }
        h = h->next_node;
    }

    params->env_head = add_node(&(params->env_head), name, value);
    params->status = 0;
}
