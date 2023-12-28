#include "shell.c"

/**
 * signal_handler - handles the signals
 * @sig_id: the idendifier of the signal to handle
 */

void signal_handler(int sig_id)
{
	if (sig_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
