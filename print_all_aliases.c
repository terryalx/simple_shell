#include "shell.h"

/**
 * print_all_aliases - Prints all aliases in the alias list.
 * @params: Parameter struct containing the alias list.
 *
 * This function iterates through the alias list stored in the parameter struct
 * and prints the name and value of each alias to stdout.
 */
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}
