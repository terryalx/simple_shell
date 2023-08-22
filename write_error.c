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

    len += strlen(params->argv[0]);  /* Calculate program name length */
    strcpy(writeHead, params->argv[0]);  /* Copy program name */
    writeHead += len;

    len += strlen(": ");  /* Calculate separator length */
    strcpy(writeHead, ": ");  /* Copy separator */
    writeHead += len;

    len += strlen(get_number(params->lineCount));  /* Calculate line number length */
    strcpy(writeHead, get_number(params->lineCount));  /* Copy line number */
    writeHead += len;

    len += strlen(": ");  /* Calculate separator length */
    strcpy(writeHead, ": ");  /* Copy separator */
    writeHead += len;

    len += strlen(params->args[0]);  /* Calculate argument length */
    strcpy(writeHead, params->args[0]);  /* Copy argument */
    writeHead += len;

    len += strlen(": ");  /* Calculate separator length */
    strcpy(writeHead, ": ");  /* Copy separator */
    writeHead += len;

    len += strlen(msg);  /* Calculate error message length */
    strcpy(writeHead, msg);  /* Copy error message */

    write(STDERR_FILENO, errBuffer, len);  /* Write error message to stderr */
}
