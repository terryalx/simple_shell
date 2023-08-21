#include "main.h"
#include "shell.h"
#include "list.h"
#include <stdlib.h>

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
		if (!_strcmp(name, h->str))
		{
			free(h->val);
			h->val = val;
			h->val_len = _strlen(val);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	
	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}
