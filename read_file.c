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
	int tak_arg;
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
		tak_arg = takes_arg(tokens);
		if (tak_arg == 0)
		{
			exec_cmd_args(tokens, line_number);
		}
		else if (tak_arg == 1)
		{
			exec_cmd_noarg(tokens, line_number);
		}
		else
		{
			line_number++;
			continue;
		}
		line_number++;
	}
	free_stack();
	fclose(file_ptr);
}
/**
 * exec_cmd_args - runs opcode with arguments
 * @tokens: array of arguments
 * @line_number: line of command in file
 * description: executes an opcode that takes arguments
 * Return: nothing
*/

void exec_cmd_args(char **tokens, int line_number)
{
	stack_t *new_node;
	int val;

	if (tokens[1] != NULL)
	{
		if (is_digit(tokens[1]) == 1)
		{
			val = atoi(tokens[1]);
			free(tokens);
			new_node = get_node(val);
			/*check if getnode succeeded*/
			push(&new_node, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(tokens);
	free_stack();
	exit(EXIT_FAILURE);

}

/**
 * is_digit - Function to check if a string value contains only digits
 * @str: character pointer to evaluate
 *
 * Return: 1 if all digits, and 0 if not
 */

int is_digit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 48 && str[i] < 58)
			continue;
		else
			return (0);
	}
	return (1);
}


/**
 * exec_cmd_noarg - runs opcodes without arguments
 * @tokens: array containing command
 * @line_number: line number of cmmand
 * description: executes an opcode that does not take an argument
 * Return: nothing
*/

void exec_cmd_noarg(char **tokens, int line_number)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = get_op_func(tokens[0]);
	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
		free(tokens);
		free_stack();
		exit(EXIT_FAILURE);
	}
	free(tokens);
	f(NULL, line_number);
}
