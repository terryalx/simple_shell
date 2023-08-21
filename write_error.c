#include "shell.h"

/**
 * write_error - write error message to stderr
 * @params: parameters struct
 * @msg: error message
*/

void write_error(param_t *params, char *msg)
{
	char errBuffer[1024] = {0};
	char *writeHead = errBuffer, *bufPtr = errBuffer;

	string_copy(writeHead, params->argv[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	string_copy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	string_copy(writeHead, get_number(params->lineCount));
	writeHead = bufPtr + _strlen(bufPtr);
	string_copy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	string_copy(writeHead, params->args[0]);
	writeHead = bufPtr + _strlen(bufPtr);
	string_copy(writeHead, ": ");
	writeHead = bufPtr + _strlen(bufPtr);
	string_copy(writeHead, msg);
	writeHead = bufPtr + _strlen(bufPtr);

	write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}
