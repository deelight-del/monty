
#include "monty.h"

/**
 * pall - prints a list
 * @stack: node
 * @line_number: line number of opcode in file
 * description: prints a list
 * Return: nothing
*/


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)stack, (void)line_number;
	ptr = head;
	if (ptr == NULL)
	{
		return;
	}
	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}
