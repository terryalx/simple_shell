#include "shell.h"

/**
 * make_alias - creates a new alias and adds to alias list
 * @name: name of new alias
 * @val: value of new alias
 * @params: parameter
 */

void make_alias(char *name, char *val, param_t *params)
{
	list_t *h = params->alias_head;

	while (h)
	{
		if (!string_compare(name, h->str))
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
