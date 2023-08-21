#include "shell.h"

/**
 * print_alias - prints the value of an alias
 * @name: name of alias
 * @params: alias list
*/

void print_alias(char *name, param_t *params)
{
	unsigned int len = 0;
	list_t *ptr = params->alias_head;

	len = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, len - 1) == 0)
		{
			my_printf("%s=\'%s\'\n", ptr->str, ptr->value);
		}
		ptr = ptr->next_node;
	}
	params->status = 0;
}
