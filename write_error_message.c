#include "shell.h"

/**
 * write_error_message - Write an error message to stderr.
 * @params: The parameters.
 * @message: The error message to write.
 */
void write_error_message(const char *message)
{
    write(STDERR_FILENO, message, strlen(message));
}
