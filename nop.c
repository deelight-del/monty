#include <stdio.h>
#include "monty.h"

/**
 * nop - Function to do nothing
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	/*Do nothing*/
	return;
}
