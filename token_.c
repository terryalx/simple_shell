#include "shell.h"

/**
 * token_ - string token function
 * @str: string to be passed
 * @delim: delimiters for tokens
 * @savePtr: state
 *
 * Return: next token found in string, NULL if not found
 */
char *token_(char *str, char *delim, char **savePtr)
{
	char *ptr;
	char *modifier;
	char *end;
	int quoteFound = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, delim))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	if (*ptr == '\'')
	{
		ptr++;
		modifier = find_character_in_string(ptr, '\'');
		if (!modifier)
		{
			my_printf("no matching quote found!\n");
			exit(-1);
		}
		*modifier = '\0';
		*savePtr = modifier + 1;
		return (str_duplicate(ptr));
	}
	while (*modifier)
	{
		if (*modifier == '\'')
			quoteFound = 1;
		if (isDelim(*modifier, delim) && quoteFound == 0)
			break;
		modifier++;
	}
	if (*modifier == '\0')
		*savePtr = modifier;
	else
		*savePtr = modifier + 1;
	*modifier = '\0';
	return (str_duplicate(ptr));
}
