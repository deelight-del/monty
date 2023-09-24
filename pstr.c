#include <stdio.h>
#include "monty.h"

/**
 * pstr - function to print the str values from the top of stack head.
 * @stack: variable of stack that will be void/not.
 * @line_number: The line number that we are currently on.
 *
 * Return: Void.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = head;

	(void)stack;
	(void)line_number;

	while (temp != NULL)
	{
		if (temp->n < 1 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
