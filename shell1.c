#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else if (read > 1)
        {
            system(line);
        }
    }
    free(line);
    return (EXIT_SUCCESS);
}

