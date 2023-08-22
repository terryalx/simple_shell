#include "shell.h"

/**
 * _alias - Implements the "alias" shell command.
 * @params: Pointer to param_t struct.
 *
 * This function handles the "alias" command in the shell. It allows the user
 * to create and manage aliases for commands. If no arguments are provided, it
 * prints all the aliases currently defined. If an argument is provided in the
 * form of "alias_name=command", it sets the alias. If an argument is provided
 * without the "=" sign, it prints the command associated with the alias.
 */
void _alias(param_t *params)
{
	unsigned int i;

	if (params->tokCount == 1)
	{
		print_all_aliases(params);
		return;
	}

	for (i = 1; i < params->tokCount; i++)
	{
		if (find_character_in_string(params->args[i], '='))
		{
			set_alias(params->args[i], params);
		}
		else
		{
			print_alias(params->args[i], params);
		}
	}
}
