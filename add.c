#include <stdio.h>
#include "monty.h"

/**
 * add - Function to add the first two elements on the top of the stack
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *newnode;

	(void) stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = head->next->n + head->n;
	pop(NULL, line_number);
	pop(NULL, line_number);
	newnode = get_node(temp);
	push(&newnode, line_number);
}
