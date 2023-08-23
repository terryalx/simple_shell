#include "shell.h" 

#define BUFFER_SIZE 1024

static int write_buffer_and_reset(char *buffer, int *bufferIndex);
static int handle_argument(const char *format, va_list params, char *buffer, int *bufferIndex);

/**
 * write_buffer_and_reset - Write buffer content to stdout and reset the index
 * @buffer: Buffer to write from
 * @bufferIndex: Index to reset
 *
 * Return: Number of characters written
 */
static int write_buffer_and_reset(char *buffer, int *bufferIndex)
{
    int charCount = 0;
    charCount = write(1, buffer, *bufferIndex);
    if (charCount == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    *bufferIndex = 0;
    return charCount;
}

/**
 * handle_argument - Handle the argument and add it to the buffer
 * @format: Format specifier
 * @params: Variable argument list
 * @buffer: Buffer to add to
 * @bufferIndex: Index for the buffer
 *
 * Return: Number of characters added to the buffer
 */
static int handle_argument(const char *format, va_list params, char *buffer, int *bufferIndex)
{
    int charCount = 0;
    char *arg = NULL;

    switch (format[0])
    {
        case 'c':
            buffer[(*bufferIndex)++] = (char)va_arg(params, int);
            break;
        case 's':
        case 'd':
        case 'i':
        case 'b':
        case 'r':
        case 'R':
        case '%':
            arg = get_arg(format[0], va_arg(params, void *));
            if (!arg) {
                return -1;
            }
            charCount += write_buffer_and_reset(buffer, bufferIndex);
            charCount += print_arg(arg);
            free(arg);
            break;
        case '\0':
            buffer[(*bufferIndex)++] = '%';
            break;
        default:
            arg = get_arg('c', format[0]);
            if (!arg) {
                return -1;
            }
            charCount += write_buffer_and_reset(buffer, bufferIndex);
            charCount += print_arg(arg);
            free(arg);
    }

    return charCount;
}

/**
 * my_printf - Output text to standard output specified by format
 * @format: Directives for outputting text
 *
 * Return: Number of characters output
 */
int my_printf(const char *format, ...)
{
    int charCount = 0, formatIndex = 0, bufferIndex = 0;
    char buffer[BUFFER_SIZE] = {0};
    va_list params;

    if (!format)
        return -1;

    if (_strlen((char *)format) == 1 && format[0] == '%')
        return -1;

    formatIndex = 0;
    va_start(params, format);

    while (1)
    {
        if (bufferIndex == BUFFER_SIZE)
            charCount += write_buffer_and_reset(buffer, &bufferIndex);

        if (format[formatIndex] == '%')
        {
            formatIndex++;
            charCount += handle_argument(format + formatIndex, params, buffer, &bufferIndex);
        }
        else if (format[formatIndex] != '\0')
            buffer[bufferIndex++] = format[formatIndex++];
        else
        {
            charCount += write_buffer_and_reset(buffer, &bufferIndex);
            va_end(params);
            return charCount;
        }
    }
}
