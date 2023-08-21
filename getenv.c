#include "shell.h"

/**
 * _getenv - Value of environment variable.
 * @name: Name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 * Return: A pointer to -> value of the environment variable, or NULL if not.
 */

char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!_strcmp(name, ptr->str))
			return (_strdup(ptr->value));
		ptr = ptr->next_node;
	}
	return (NULL);
}
