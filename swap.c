#include <stdio.h>
#include "monty.h"

/**
 * swap - Function to swap the first two top of the stack
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	(void) stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = head->next->n;
	head->next->n = head->n;
	head->n = temp;
}
