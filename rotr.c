#include <stdio.h>
#include "monty.h"

/**
 * rotr - Function to rotate right
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *temp;

	(void) stack;
	(void) line_number;

	if (head == NULL || head->next == NULL)
		return;

	else
	{
		temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		last = temp;
		last->prev->next = NULL;
		temp = head;
		temp->prev = last;
		last->next = temp;
		last->prev = NULL;
		head = last;
	}
}
