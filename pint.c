#include <stdio.h>
#include "monty.h"

/**
 * pint - function to print the value at the top of stack head.
 * @stack: variable of stack that will be void/not.
 * @line_number: The line number that we are currently on.
 *
 * Return: Void.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	printf("I am entering here to print the last\n");
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", head->n);
	}

}
