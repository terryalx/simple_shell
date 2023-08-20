#include "shell.h"

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
	list_t *h = params->alias_head;

	while (h)
	{
		if (!_strcmp(name, h->str))
		{
			free(h->value);
			h->value = val;
			h->value_length = _strlen(val);
			params->status = 0;
			return;
		}
		h = h->next_node;
	}
	
	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}
