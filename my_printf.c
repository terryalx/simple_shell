#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * Process a format specifier and update the buffer.
 */
static int process_format_specifier(char *buffer, int *bufferIndex, const char *format, int *formatIndex, va_list params)
{
    char *arg = NULL;

    switch (format[*formatIndex])
    {
        case 'c':
            buffer[*bufferIndex] = (char)va_arg(params, int);
            (*bufferIndex)++;
            (*formatIndex)++;
            return (1);

        case 's':
            arg = get_arg('s', va_arg(params, char *));
            if (arg == NULL)
                return (0); 
            while (*arg)
            {
                buffer[*bufferIndex] = *arg;
                (*bufferIndex)++;
                arg++;
            }
            return (1);

        case 'd':
        case 'i':
            return (1);

        case 'b':
            return (1);

        case 'r':
            return (1);

        case 'R':
            return (1);

        case '%':
            arg = malloc(2);
            arg[0] = '%';
            arg[1] = '\0';
            return (1);

        case '\0':
            buffer[*bufferIndex] = '%';
            (*bufferIndex)++;
            (*formatIndex)++;
            return (1);

        default:
            arg = malloc(3);
            arg[0] = '%';
            arg[1] = format[*formatIndex];
            arg[2] = '\0';
            return (1);
    }
}

/**
 * my_printf - Output text to standard output specified by format
 * @format: Directives for outputting text
 *
 * Return: Number of characters output
 */
int my_printf(const char *format, ...)
{
    int formatIndex, charCount = 0, returnValue = -1, bufferIndex = 0;
    char buffer[BUFFER_SIZE] = {0};
    char *arg = NULL;
    va_list params;

    if (!format)
        return (returnValue);

    if (_strlen((char *)format) == 1 && format[0] == '%')
        return (returnValue);

    formatIndex = 0;
    va_start(params, format);

    while (1)
    {
        if (bufferIndex == BUFFER_SIZE)
        {
            charCount += write_and_reset_buffer(buffer, &bufferIndex);
        }

        if (format[formatIndex] == '%')
        {
            get_type((char *)format, &formatIndex);

            int charsProcessed = process_format_specifier(buffer, &bufferIndex, format, &formatIndex, params);

            if (charsProcessed == 0)
            {
                va_end(params);
                return (returnValue);
            }

            charCount += charsProcessed;
        }
        else if (format[formatIndex] != '\0')
        {
            buffer[bufferIndex] = format[formatIndex];
            bufferIndex++;
            formatIndex++;
        }
        else
        {
            charCount += write_and_reset_buffer(buffer, &bufferIndex);
            va_end(params);
            return (charCount);
        }
    }

    return (charCount);
}
