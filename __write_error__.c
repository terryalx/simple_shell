#include "shell.h"

/**
 * __write_error__ - Write an error message to stderr.
 * @params: Parameters struct containing program information.
 * @msg: Error message to be written.
 *
 * This function writes an error message to the
 * standard error stream (stderr). It constructs an
 * error message including the program name, line number, and
 * the provided error message, and then writes it to stderr.
 */
void __write_error__(param_t *params, char *msg)
{
	char errBuffer[1024] = {0};
	char *writeHead = errBuffer;

	writeHead = stpncpy(writeHead, params->argv[0],
			sizeof(errBuffer) - (writeHead - errBuffer));
	writeHead = stpncpy(writeHead, ": ",
			sizeof(errBuffer) - (writeHead - errBuffer));
	writeHead = stpncpy(writeHead, get_number(params->lineCount),
			sizeof(errBuffer) - (writeHead - errBuffer));
	writeHead = stpncpy(writeHead, ": ",
			sizeof(errBuffer) - (writeHead - errBuffer));
	writeHead = stpncpy(writeHead, params->args[0],
			sizeof(errBuffer) - (writeHead - errBuffer));
	writeHead = stpncpy(writeHead, ": ",
			sizeof(errBuffer) - (writeHead - errBuffer));
	stpncpy(writeHead, msg,
			sizeof(errBuffer) - (writeHead - errBuffer));

	write(STDERR_FILENO, errBuffer, strlen(errBuffer));
}
