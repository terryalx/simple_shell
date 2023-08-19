#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * make_alias - creates a new alias and adds it to the alias list
 * @name: name of the new alias
 * @val: value of the new alias
 * @params: parameter
 *
 * Return: void
 */
void make_alias(char *name, char *val, param_t *params)
{
	list_t *alias_node = params->alias_head;

	while (alias_node)
	{
		if (!_strcmp(name, alias_node->str))
		{
			free(alias_node->val);
			alias_node->val = strdup(val);
			alias_node->val_len = strlen(val);
			params->status = 0;
			return;
		}
		alias_node = alias_node->next;
	}

	params->alias_head = add_node(&(params->alias_head), name, strdup(val));
	free(val);
	params->status = 0;
}
