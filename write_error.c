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
    size_t len = 0;  /* Length of the error message */

    len += string_copy(writeHead, params->argv[0]);  /* Copy program name */
    writeHead += len;
    len += string_copy(writeHead, ": ");  /* Copy separator */
    writeHead += len;
    len += string_copy(writeHead, get_number(params->lineCount));  /* Copy line number */
    writeHead += len;
    len += string_copy(writeHead, ": ");  /* Copy separator */
    writeHead += len;
    len += string_copy(writeHead, params->args[0]);  /* Copy argument */
    writeHead += len;
    len += string_copy(writeHead, ": ");  /* Copy separator */
    writeHead += len;
    len += string_copy(writeHead, msg);  /* Copy error message */
    writeHead += len;

    write(STDERR_FILENO, errBuffer, len);  /* Write error message to stderr */
}
