#include "monty.h"
/**
 * read_file - reads a line from a file
 * @buff: buffer to store the line
 * @n: number of bytes read
 * @file_path: path of file to read
 * Return: number of bytes read or -1
*/


void read_file(char *buff, int n, char *file_path)
{
	FILE *file_ptr;
	char **tokens;
	int tak_arg, val;
	stack_t *new_node;
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int line_number;

	file_ptr = fopen(file_path, "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Can't open %s\n", get_name(file_path));
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(buff, n, file_ptr))
	{
		tokens = get_tokens(buff);
		tak_arg = takes_arg(tokens[0]);
		if (tak_arg == 0)
		{
			val = atoi(tokens[1]);
			if (tokens[1] == NULL || val == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(tokens);
				exit(EXIT_FAILURE);
			}
			new_node = get_node(val);
			push(&new_node, line_number);
		}
		else if (tak_arg == 1)
		{
			f = get_op_func(tokens[0]);
			f(NULL, line_number);
		}
		else
		{
			free(tokens);
			line_number++;
			continue;
		}
		free(tokens);
		line_number++;
	}
	fclose(file_ptr);
}
