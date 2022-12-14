#include "monty.h"
/**
 * scan_file - function to execute a Monty bytecodes script.
 * @file: File descriptor for an open Monty bytecodes script.
 *
 * Return: nothing.
 */
void scan_file(FILE *file)
{
	size_t n = 0;
	char *buffer = NULL, *token = NULL, *token1 = NULL;
	unsigned int line_number = 0;
	char *delimiter = "\n\t\r ";
	stack_t *stack = NULL;
	/*int result;*/

	while (getline(&buffer, &n, file) != -1)
	{
		line_number++;
		token = strtok(buffer, delimiter);
		if (token == NULL || strncmp(token, "#", 1) == 0)
			continue;
		token1 = strtok(NULL, delimiter);
		get_op_func(token, token1, &stack, line_number);
		/*printf("token1 = %s\n", token1);*/
		/*if (result == 1)
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);*/
	}
}
