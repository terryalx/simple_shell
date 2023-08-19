#include "shell.h"
#include <stdlib.h>

/**
 * rev_string - Reverses the order of characters in a string.
 * @s: A pointer to a null-terminated string to be reversed.
 *
 * Return: void
 */
void rev_string(char *s)
{
	int head = 0, tail = 0;
	int len = 0;
	char tmp;

	if (s == NULL)
		s = "(null)";

	for (len = 0; s[len] != '\0'; len++)
		;

	tail = len - 1;

	while (head < tail)
	{
		tmp = s[head];
		s[head] = s[tail];
		s[tail] = tmp;
		head++;
		tail--;
	}
}
