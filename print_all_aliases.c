#include "shell.h"

/**
 * print_all_aliases - prints all aliases in the alias list
 * @params: alias list
*/
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}
