#include "monty.h"

/**
 * takes_arg - checks if the functions takes argument
 * @opc: opcode
 * description: checks if an opcode takes argumets or not
 * Return: 0 (takes args) 1 (does not) -1 (bad opcode)
*/


int takes_arg(char *opc)
{
	if (opc == NULL)
		return (-1);
	else if (strcmp(opc, "push") == 0)
		return (0);
	else
		return (1);
}
