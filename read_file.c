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
	file_ptr = fopen(file_path, "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Can't open %s\n", get_name(file_path));
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, n, file_ptr))
	{
		tokens = get_tokens(buff);
		tak_arg = takes_arg(tokens[0]);
		if (tak_arg == 0)
		{
			/*push was entered*/
			if (tokens[1] == NULL || val == 0)
			{
				/*print error*/
			}
		}
		else if (tak_arg == 1)
		{
			/*doesn't take an arg*/
		}
		else
		{
			/*was an empty line so continue to next*/
			continue;
		}
		print_arr(tokens);
		free(tokens);
	}
	fclose(file_ptr);
}
