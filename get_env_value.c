#include "shell.h"

/**
 * get_env_value - Retrieve the value of an environment variable.
 * @name: Name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not found.
 */
char *get_env_value(char *name, param_t *params)
{
    list_t *ptr = params->env_head;

    while (ptr)
    {
        if (string_compare(name, ptr->str) == 0)
        {
            char *value = str_duplicate(ptr->value);
            if (!value)
            {
				/**
				 * Handle memory allocation error if needed
				 * For example, log an error message and return NULL or
				 * set an error code.
				*/
                return NULL;
            }
            return value;
        }
        ptr = ptr->next_node;
    }

    /**
	 * Environment variable not found, you can handle this case accordingly.
	 * For example, log an error message or set an error code.
	 * */ 
    return NULL;
}
