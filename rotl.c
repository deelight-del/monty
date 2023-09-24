#include <stdio.h>
#include "monty.h"

/**
 * rotl - Function to rotate left
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *temp, *new_head;

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
		temp = head;
		new_head = head->next;
		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
		new_head->prev = NULL;
		head = new_head;
	}
}
