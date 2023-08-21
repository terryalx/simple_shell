#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _printf - Output text to standard output specified by format
 * @format: Directives for outputting text
 * 
 * Return: Number of characters output
 */
int _printf(const char *format, ...)
{
    int charCount = 0, returnValue = -1, bufferIndex = 0;
    char buffer[BUFFER_SIZE] = {0};
    va_list params;

    if (!format)
        return (returnValue);

    if (_strlen((char *)format) == 1 && format[0] == '%')
        return (returnValue);

    va_start(params, format);

    for (int formatIndex = 0; format[formatIndex]; formatIndex++)
    {
        if (bufferIndex == BUFFER_SIZE)
            charCount += flush_buffer(buffer, &bufferIndex);

        if (format[formatIndex] == '%')
        {
            formatIndex++;
            if (format[formatIndex] == '\0')
            {
                buffer[bufferIndex] = '%';
                bufferIndex++;
                continue;
            }

            char *arg = NULL;

            switch (format[formatIndex])
            {
            case 'c':
                buffer[bufferIndex++] = (char)va_arg(params, int);
                continue;
            case 's':
            case 'd':
            case 'i':
            case 'b':
            case 'r':
            case 'R':
                arg = get_arg(format[formatIndex], va_arg(params, void *));
                break;
            default:
                arg = malloc(3);
                if (arg)
                {
                    arg[0] = '%';
                    arg[1] = format[formatIndex];
                    arg[2] = '\0';
                }
            }

            if (!arg)
            {
                va_end(params);
                return (returnValue);
            }

            charCount += flush_buffer(buffer, &bufferIndex);
            charCount += print_arg(arg);
            free(arg);
        }
        else
        {
            buffer[bufferIndex++] = format[formatIndex];
        }
    }

    charCount += flush_buffer(buffer, &bufferIndex);
    va_end(params);

    return (charCount);
}
