#include "shell.h"
#include <stdlib.h>

/**
 * set_alias - creates a new or updates an existing alias
 * @name: the name of the alias
 * @params: state
 * Return: void
 */

void set_alias(char *name, param_t *params)
{
	char *val, *tmp = NULL;
	unsigned int i = 0, j = 1;

	while (name[i] && name[i] != '=')
		i++;
	if (name[i + 1] == '\'')
	{
		if (_strchr(&name[i + 2], '\''))
		{
			tmp = _strchr(&name[i + 2], '\'');
			*tmp = '\0';
			val = _strdup(&name[i + 2]);
			if (tmp[1] != '\0')
			{
				while (tmp[j] &&
					(tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n'))
					j++;
				if (tmp[j] != '\0')
					set_alias(&tmp[j], params);
			}
		}
		else
		{
			_printf("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
		val = _strdup(&name[i + 1]);
	name[i] = '\0';
	make_alias(name, val, params);
}
