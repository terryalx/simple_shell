#include "shell.h"
#include <stdlib.h>

/**
 * print_all_aliases - prints all aliases in the alias list
 * @params: pointer to the param_t struct
 *
 * This function takes a pointer to the param_t struct and prints all the aliases
 * in the alias list.
 */
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}
