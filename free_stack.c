#include <stdio.h>
#include "monty.h"

/**
 * free_stack - Function to free the stack
 *
 * Return: void.
 */

void free_stack(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head->next)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	free(head);
}
