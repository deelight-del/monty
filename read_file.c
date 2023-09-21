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

	file_ptr = fopen(file_path, "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Can't open %s\n", get_name(file_path));
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, n, file_ptr))
	{
		printf("%s", buff);
	}
	fclose(file_ptr);
}
