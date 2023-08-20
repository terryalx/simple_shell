#include "shell.h"

/**
 * rot13 - performs ROT13 encryption on a string
 * @plaintext: string to be encrypted
 *
 * Return: pointer to the encrypted string
 */
char *rot13(char *s)
{
    char *ptr;
    int i;
    const char *original = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *encrypted = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

    for (ptr = s; *ptr != '\0'; ptr++)
    {
        for (i = 0; i < (int)(sizeof(original) - 1); i++)
        {
            if (*ptr == original[i])
            {
                *ptr = encrypted[i];
                break;
            }
        }
    }
    return (s);
}
