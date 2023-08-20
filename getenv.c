#include "shell.h"

/**
 * _getenv - Retrieve the value of an environment variable.
 * @name: Name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not found.
 */
char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!string_compare(name, ptr->str))
			return (_strdup(ptr->value));
		ptr = ptr->next_node;
	}
	return (NULL);
}
