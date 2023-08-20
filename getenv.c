#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Retrieve the value of an environment variable.
 * @name: Name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name, param_t *params)
{
	list_t *currentNode = params->env_head;

	while (currentNode)
	{
		if (strcmp(name, currentNode->str) == 0)
			return strdup(currentNode->val);
		currentNode = currentNode->next;
	}

	/* Environment variable not found */

	return NULL;
}
