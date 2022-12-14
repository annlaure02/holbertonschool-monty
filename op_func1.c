#include "monty.h"

int value;
/**
 * _push - pushe an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of line
 *
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n = value;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - print all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of line
 *
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - print the value at the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of line
 *
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _swap - swap the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of line
 *
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * _nop - doesn’t do anything
 * @stack: pointer to the head of the stack
 * @line_number: number of line
 *
 * Return: void
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
