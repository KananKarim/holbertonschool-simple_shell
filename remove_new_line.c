#include "shell.c"

/**
 * remove_new_line - removes a newline char from string
 * @str: the string
 *
 * Return: the string without a new line char
 */

char *remove_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\n';
		i++;
	}

	return (str);
}
