#include "shell.h"
#include <unistd.h>

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

	_strcpy(writeHead, params->args[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, get_number(params->lineCount));
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	_strcpy(writeHead, msg);
	writeHead = bufPtr + _strlen(bufPtr);

	if (params->status != 0)
	{
		_strcpy(writeHead, ": ");
		writeHead = bufPtr + _strlen(bufPtr);
		_strcpy(writeHead, get_number(params->status));
		writeHead = bufPtr + _strlen(bufPtr);
	}

	_strcpy(writeHead, "\n");
	write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}
