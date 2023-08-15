/**
 * set_alias - creates a new alias or updates an existing one
 * @name: the name of the alias to set
 * @params: shell state
 *
 * This function sets a new alias or updates an existing one in the shell.
 * An alias is a command or group of commands that can be referred to by
 * a name. For example, "ll" can be an alias for "ls -l". The alias is
 * stored as a key-value pair in the shell's list of aliases.
 *
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
	name[i] = '\0'; /* set = to terminater */
	make_alias(name, val, params);
}

