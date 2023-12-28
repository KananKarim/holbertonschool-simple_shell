#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

