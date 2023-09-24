#include <stdio.h>
#include "monty.h"

/**
 * pchar - function to print the char value at the top of stack head.
 * @stack: variable of stack that will be void/not.
 * @line_number: The line number that we are currently on.
 *
 * Return: Void.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", head->n);
	}

}
