#include "monty.h"

/**
 * main - main function.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * If the user does not give any file or more than one argument,
 * print the error message USAGE: monty file, exit status EXIT_FAILURE.
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	scan_file(file);
	fclose(file);
	exit(EXIT_SUCCESS);
}
