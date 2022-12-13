#include "monty.h"
/**
 * get_op_func - get function.
 * @op:	TBD
 * @stack: TBD
 * @line_number: TBD
 * Return: Nothing.
 */
void get_op_func(char *op, stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t code_list[] = {
		{"push", _push},
		{"pall", _pall},
		/*{"pint", _pint},*/
		/*{"pop", _pop},*/
		/*{"swap", _swap},*/
		/*{"add", _add},*/
		/*{"nop", _nop},*/
		{NULL, NULL}
	};

	while (code_list[i].opcode != NULL)
	{
		if (strcmp(code_list[i].opcode, op) == 0)
		{
			code_list[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
