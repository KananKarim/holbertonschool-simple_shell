#include "main.h"


/**
 * main - Entry point for the shell
 *
 * Description: This function is the entry point for the shell program. It
 * displays a prompt, waits for the user to type a command, and executes it.
 * If the command cannot be executed, it prints an error message.
 * handles the "end of file" condition (Ctrl+D).
 *
 * Return: 0 on success, or an error code on failure.
 */


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#shell$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			free(line);
			exit(EXIT_SUCCESS);
		}

		else if (read > 1)
		{
			system(line);
		}
	}

	return (0);
}
