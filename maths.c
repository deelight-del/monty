#include <stdio.h>
#include "monty.h"

/**
 * sub - Function to subtract the first two elements on the top of the stack
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *newnode;

	(void) stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = head->next->n - head->n;
	pop(NULL, line_number);
	pop(NULL, line_number);
	newnode = get_node(temp);
	push(&newnode, line_number);
}


/**
 * div_m - opcode to divide the second top element by the top
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void div_m(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *newnode;

	(void) stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = head->next->n / head->n;
	pop(NULL, line_number);
	pop(NULL, line_number);
	newnode = get_node(temp);
	push(&newnode, line_number);
}


/**
 * mul - Function to multiply the first two elements on the top of the stack
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *newnode;

	(void) stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = head->next->n * head->n;
	pop(NULL, line_number);
	pop(NULL, line_number);
	newnode = get_node(temp);
	push(&newnode, line_number);
}


/**
 * mod - opcode to get the mod of the second top element by the top element
 * @stack: An optional stack to include
 * @line_number: The line number to use for error
 *
 * Return: void.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *newnode;

	(void) stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = head->next->n % head->n;
	pop(NULL, line_number);
	pop(NULL, line_number);
	newnode = get_node(temp);
	push(&newnode, line_number);
}


