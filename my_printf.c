#include "shell.h"

#define BUFFER_SIZE 1024

int handle_char_format(char *buffer, int *bufferIndex, va_list params) {
    buffer[(*bufferIndex)++] = (char)va_arg(params, int);
    return 1;
}

int handle_string_format(char *buffer, int *bufferIndex, va_list params) {
    char *arg = va_arg(params, char*);
    int charCount = 0;

    if (arg == NULL) {
        arg = "(null)";
    }

    while (*arg) {
        if (*bufferIndex == BUFFER_SIZE) {
            charCount += write_and_reset_buffer(buffer, bufferIndex);
        }
        buffer[(*bufferIndex)++] = *arg++;
        charCount++;
    }

    return charCount;
}

int my_printf(const char *format, ...) {
    int formatIndex, charCount = 0, returnValue = -1, bufferIndex = 0;
    char buffer[BUFFER_SIZE] = {0};
    va_list params;

    if (!format)
        return (returnValue);

    if (_strlen((char *)format) == 1 && format[0] == '%')
        return (returnValue);

    formatIndex = 0;
    va_start(params, format);

    while (1) {
        if (bufferIndex == BUFFER_SIZE) {
            charCount += write_and_reset_buffer(buffer, &bufferIndex);
        }

        if (format[formatIndex] == '%') {
            get_type((char *)format, &formatIndex);

            switch (format[formatIndex]) {
                case 'c':
                    charCount += handle_char_format(buffer, &bufferIndex, params);
                    break;
                case 's':
                    charCount += handle_string_format(buffer, &bufferIndex, params);
                    break;
                default:
                    fprintf(stderr, "Error: Unsupported format specifier: %%%c\n", format[formatIndex]);
                    va_end(params);
                    return -1;
            }

            formatIndex++;
        } else if (format[formatIndex] != '\0') {
            buffer[bufferIndex++] = format[formatIndex++];
            charCount++;
        } else {
            charCount += write_and_reset_buffer(buffer, &bufferIndex);
            va_end(params);
            return (charCount);
        }
    }

    return (charCount);
}
