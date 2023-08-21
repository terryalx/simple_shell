#include "shell.h"

/**
 * get_binary - Convert an unsigned integer to its binary representation.
 * @n: The unsigned integer to be converted.
 *
 * This function converts an unsigned integer into its binary representation
 * and returns a pointer to the resulting binary string.
 *
 * @n: The integer to convert to binary.
 *
 * Return: A pointer to the binary string representation of the integer,
 *         or NULL if memory allocation fails.
 */
char *get_binary(unsigned int n)
{
    char *ptr = NULL;
    unsigned int i, num = 0, size = 0;

    if (n == 0)
    {
        ptr = malloc(2);
        if (ptr)
        {
            ptr[0] = '0';
            ptr[1] = '\0';
        }
        return (ptr);
    }
    size = sizeof(unsigned int) * 8 + 1;
    ptr = malloc(size);
    if (ptr)
    {
        for (i = 0; i < size; i++)
        {
            ptr[i] = '0';
        }
        ptr[size - 1] = '\0';

        i = size - 2;
        while (n != 0)
        {
            ptr[i] = n % 2 == 0 ? '0' : '1';
            num++;
            n = n / 2;
            i--;
        }
        num++;
        ptr = move_left(ptr, size, num);
    }
    return (ptr);
}
