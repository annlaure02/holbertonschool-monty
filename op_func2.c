#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line of the command
 * Return: nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	current = *stack;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}

/**
 * _add - adds the top two elements of the stack
 * @stack: stack storing data
 * @line_number: line of the command
 * Return: nothing
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int i = 0, sum = 0;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	_pop(stack, line_number);
}
