#include "shell.h"
#include <stdlib.h>

/**
 * set_alias - creates a new or updates an existing alias
 * @name: the name of the alias
 * @state: the state of the program
 *
 * Return: void
 */
void set_alias(char *name, param_t *state)
{
	char *alias_value;
	char *closing_quote = NULL;
	unsigned int i = 0;

	while (name[i] && name[i] != '=')
		i++;

	if (name[i + 1] == '\'')
	{
		if (_strchr(&name[i + 2], '\''))
		{
			closing_quote = _strchr(&name[i + 2], '\'');
			*closing_quote = '\0';
			alias_value = _strdup(&name[i + 2]);

			if (closing_quote[1] != '\0')
				set_alias(&closing_quote[1], state);
		}
		else
		{
			printf("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
		alias_value = _strdup(&name[i + 1]);

	name[i] = '\0';
	make_alias(name, alias_value, state);
}
