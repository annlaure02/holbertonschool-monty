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
		exit(EXIT_FAILURE);
	}
	printf("n = %i\n", n);
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
