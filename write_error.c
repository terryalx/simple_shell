#include "shell.h"

/**
 * write_error - Write error message to stderr
 * @params: Parameters struct
 * @msg: Error message
 *
 * Description: This function writes an error message to the standard error stream.
 * It takes a parameters struct and an error message as input. The function constructs
 * an error buffer and copies various strings into it. Finally, it writes the contents
 * of the error buffer to the standard error stream.
 */
void write_error(param_t *params, char *msg)
{
    char errBuffer[1024] = {0};  /* Error buffer */
    char *writeHead = errBuffer;  /* Pointer to the current write position */
    int len = 0;  /* Length of the error message */

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
