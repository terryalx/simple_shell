#include "shell.h"

/**
 * write_error - Write an error message to stderr.
 * @params: Parameters struct containing program information.
 * @msg: Error message to be written.
 *
 * This function writes an error message to the standard error stream (stderr).
 * It constructs an error message including the program name, line number, and
 * the provided error message, and then writes it to stderr.
 */
void write_error(param_t *params, char *msg)
{
    char errBuffer[1024] = {0};  /* Error buffer */
    char *writeHead = errBuffer;  /* Pointer to the current write position */

    /* Copy program name */
    writeHead = stpncpy(writeHead, params->argv[0], sizeof(errBuffer) - (writeHead - errBuffer));

    /* Copy separator ": " */
    writeHead = stpncpy(writeHead, ": ", sizeof(errBuffer) - (writeHead - errBuffer));

    /* Copy line number */
    writeHead = stpncpy(writeHead, get_number(params->lineCount), sizeof(errBuffer) - (writeHead - errBuffer));

    /* Copy separator ": " */
    writeHead = stpncpy(writeHead, ": ", sizeof(errBuffer) - (writeHead - errBuffer));

    /* Copy argument */
    writeHead = stpncpy(writeHead, params->args[0], sizeof(errBuffer) - (writeHead - errBuffer));

    /* Copy separator ": " */
    writeHead = stpncpy(writeHead, ": ", sizeof(errBuffer) - (writeHead - errBuffer));

    /* Copy error message */
    stpncpy(writeHead, msg, sizeof(errBuffer) - (writeHead - errBuffer));

    /* Write error message to stderr */
    write(STDERR_FILENO, errBuffer, strlen(errBuffer));
}
