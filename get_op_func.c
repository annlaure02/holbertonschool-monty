#include "monty.h"
/**
 * get_op_func - get function.
 * @op:	opcode
 * @data: data
 * @stack: pointer to the head of the stack
 * @line_nb: number of line
 * Return: 0 on success, 1 if there is no data, 2 if different of opcode.
 */
int get_op_func(char *op, char *data, stack_t **stack, unsigned int line_nb)
{
	unsigned int i = 0;

	instruction_t code_list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (code_list[i].opcode)
	{
		if (!strcmp(code_list[i].opcode, op))
		{
			if (!strcmp(op, "push"))
			{
				if (_isdigit(data) == 1)
					value = atoi(data);
				else
					return (1);
			}
			code_list[i].f(stack, line_nb);
			break;
		}
		i++;
	}
	if (!code_list[i].opcode)
	{
		return (2);
	}

	return (0);
}
