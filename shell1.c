#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void display_prompt() {
    printf("#cisfun$ ");
}

int main(void) {
    char input[MAX_INPUT_SIZE];
    int status;
    pid_t child_pid;

    while (1) {
        display_prompt();

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            if (execlp(input, input, (char *)NULL) == -1) {
                perror("exec");
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 127) {
                printf("%s: command not found\n", input);
            }
        }
    }

    return 0;
}

