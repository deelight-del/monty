#include "monty.h"


/**
 * get_op_func - gets the function of an opcode
 * @str: string
 * description: gets the function corresponding to an opcode
 * Return: pointer to opcode function or NULL
*/


void (*get_op_func(char *str))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		/*{"nop", nop},*/
		{NULL, NULL}
	};

	int i;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, str) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
