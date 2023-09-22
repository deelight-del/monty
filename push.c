#include "monty.h"

/**
 * push - push a node unto the stack
 * @stack: node
 * @line_number: line number of opcode in file
 * description: pushes a node unto the stack
 * Return: nothing
*/

stack_t **head = NULL;

void push(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	if (*head == NULL)
	{
		head = *stack;
	}
	else
	{
		(*stack)->next = *head;
		(*head)->prev = *stack;
		*head = stack;
	}
}
