#include "main.h"

/**
 * main - Entry point of the program.
 * This function continuously reads lines from the standard input,
 * executes them as system commands, and then prints a prompt for
 *
 * Return: EXIT_SUCCESS upon successful termination.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			if (!feof(stdin))
				printf("\n");
			exit(EXIT_SUCCESS);
		}
		else if (read > 1)
		{
			line[strcspn(line, "\n")] = 0;
			system(line);
		}
	}
	return (EXIT_SUCCESS);
}
