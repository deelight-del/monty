#include "monty.h"
#include <stdio.h>


/**
 * main - The main funciton of our monty file
 * @argc: The count of the arguments
 * @argv: vector of string arguments
 *
 * Return: An integer.
 */

int main(int argc, char **argv)
{
	char buff[100];
	int  n;
	n = 100;
	
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(buff, n, argv[1]);
	return (0);
}
