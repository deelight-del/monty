#include <stdio.h>
#include <stdlib.h>
/*include monty.h*/

/**
 * main - The main funciton of our monty file
 * @argc: The count of the arguments
 * @argv: vector of string arguments
 *
 * Return: An integer.
 */

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
