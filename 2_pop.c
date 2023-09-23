#include <stdio.h>
#include "monty.h"

/**
 * pop - Function to pop the topmost element/node in a stack
 * @stack: stack_t data type
 * @line_number: The line number that we are on
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) stack;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->next == NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	else
	{
		temp = head->next;
		temp->prev = head->prev;
		free(head);
		head = temp;
	}

}
