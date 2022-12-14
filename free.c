#include "monty.h"
/**
 * free_dlist - function that frees a list.
 * @head: A pointer to the head of the list.
 * Return: nothing.
 */
void free_dlist(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
