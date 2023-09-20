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
	char *buff;
	size_t n;

	n = 0;
	buff = NULL;
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(&buff, &n, argv[1]);
	printf("%s\n", buff);
	return (0);
}
