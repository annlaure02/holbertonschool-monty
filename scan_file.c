#include "monty.h"
/**
 * scan_file - function to execute a Monty bytecodes script.
 * @file: File descriptor for an open Monty bytecodes script.
 *
 * Return: nothing.
 */
void scan_file(FILE *file)
{
	ssize_t read = 0;
	size_t n = 0;
	char *buffer = NULL, *op = NULL;
	unsigned int line_number = 0;
	char *delimiter = "\n\t\r ";
	stack_t *stack = NULL;

	while ((read = getline(&buffer, &n, file)) != -1)
	{
		line_number++;
		op = strtok(buffer, delimiter);
		if (op == NULL || strncmp(op, "#", 1) == 0)
			continue;
		get_op_func(op, &stack, line_number);
	}
	if (read == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}
