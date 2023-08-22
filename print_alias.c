#include "shell.h"

/**
 * print_alias - Prints the value of an alias.
 * @name: Name of the alias.
 * @params: Alias list.
 *
 * Return: None.
 */
void print_alias(char *name, param_t *params)
{
	unsigned int len = _strlen(name);
	list_t *ptr = params->alias_head;

	while (ptr)
	{
		if (strncmp_custom(name, ptr->str, len - 1) == 0)
		{
			my_printf("%s='%s'\n", ptr->str, ptr->value);
		}
		ptr = ptr->next_node;
	}

	params->status = 0;
}
