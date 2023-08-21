#include "shell.h"

/**
 * write_error - write error message to stderr
 * @params: parameters struct
 * @msg: error message
 *
 * Return: void
 */
void write_error(param_t *params, char *msg)
{
	char errBuffer[1024] = {0};
	char *writeHead = errBuffer, *bufPtr = errBuffer;

	strcpy(writeHead, params->argv[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	strcpy(writeHead, get_number(params->lineCount));
	writeHead = bufPtr + _strlen(bufPtr);
	strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	strcpy(writeHead, params->args[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	strcpy(writeHead, msg);
	writeHead = bufPtr + _strlen(bufPtr);

	write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}
